/*  DNF generator
	
	Yusef Ajoodani
	
	last edited:
		92/7/30
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

struct lit {
	char c;
	bool negated;
	
	lit(): negated(false) {	}
};

typedef vector <lit> vl;
typedef vector < vl > vvl;

bool operator< (const lit &a, const lit &b){
	return a.c<b.c || (a.c==b.c && (!a.negated && b.negated));
}

bool operator== (const lit &a, const lit &b){
	return a.c==b.c && a.negated==b.negated;
}

bool operator!= (const lit &a, const lit &b){ // to check the form p^~p
	return a.c==b.c && a.negated!=b.negated;
}

bool operator< (const vl &a, const vl &b){
	if (a.size()!=b.size())
		return a.size()<b.size();
		
	int size= a.size();
	for (int i=0; i<size; ++i){
		if (a[i]<b[i])
			return true;
		else if (b[i]<a[i])
			return false;
	}
	
	return false;
}

bool operator== (const vl &a, const vl &b){
	if (a<b || b<a)
		return false;
	
	int size=a.size();
	for (int i=0; i<size; ++i)
		if (a[i].negated!=b[i].negated)
			return false;
	return true;
}

int rightPar (string &s, int lpar) {
	int ln=1, rn=0, size=s.size();
	
	for (int i=lpar+1; i<size; ++i){
		if (s[i]=='(')
			++ln;
		else if (s[i]==')')
			++rn;
		
		if (ln==rn)
			return i;
	}
	
	return -1; // not found
}

int leftFormEnd (string &s, int l){
	if (s[l]!='(' )
		return l+1;
	
	return rightPar(s, l)+1;
}

struct formula {
	char v; //variable
	formula *left, *right;
	char con; // connective:: and: ^ , or: | , implication: > , iff: =
	bool negated /* ~ */, atomic;
	
	formula(): negated(false), atomic(true), left(NULL), right(NULL) {	}
	
	void clear (){
		if (left!=NULL)
			left->clear();
		if (right!=NULL)
			right->clear();
		
		atomic=true;
		negated=false;
		delete left;
		delete right;
		left= NULL;
		right= NULL;
	}
	
	~formula (){
		clear();
	}
	
	void build (string &s, bool &wff){
		if (!wff) // not well-formed
			return;
		int size= s.size();
		if (size>2 && s[0]=='(' && rightPar(s, 0)==size-1){
			for (int i=1; i<size; ++i)
				s[i-1]=s[i];
				s.resize(s.size()-2);
				build (s, wff);
				return;
		}
		if (size<3){
			atomic=true;
			if (size==1){
				switch (s[0]){
					case '(': 
					case ')':
					case '~':
					case '^': 
					case '|':
					case '>':
					case '=':
						wff=false;
						return;
				}
				negated=false;
				v=s[0];
			}
			else{ // size==2
				if (s[0]!='~'){
					wff=false;
					return;
				}
				switch (s[1]){
					case '(': 
					case ')':
					case '~':
					case '^': 
					case '|':
					case '>':
					case '=':
						wff=false;
						return;
				}
				negated=true;
				v=s[1];
			}
		}
		else {
			atomic=false;
			negated=false;
			string ls, rs;
			bool lneg/*, rneg*/;
			int lbegin, lend, rbegin, rend=size;
			
			if (s[0]=='~'){
				lneg=true;
				lbegin=1;
			}
			else{
				lneg=false;
				lbegin=0;
			}
			lend= leftFormEnd (s, lbegin);
			if (lend==0){ //parentheses not balanced
				wff=false;
				return;
			}
			if (lend==size){ // s is the form "~(Q)" (also lneg will be true!)
				s= s.substr(1, size-1);
				build(s, wff);
				negated=!negated;
				return;
			}
			con= s[lend];
			switch (con){
				case '^': 
				case '|':
				case '>':
				case '=':
					break; // do nothing
				default:
					wff=false;
					return;
			}
			
			rbegin=lend+1;
//			if (s[rbegin]=='~'){	//bugged
//				++rbegin;
//				rneg=true;
//			}
//			else
//				rneg=false;
			
			if (s[lbegin]=='('){
				++lbegin;
				--lend;
			}
//			if (s[rbegin]=='('){	//bugged
//				++rbegin;
//				--rend;
//			}
			
			ls=s.substr(lbegin, lend-lbegin);
			rs=s.substr(rbegin, rend-rbegin);
			
			if (con=='='){
				if (lneg){
					ls.resize(ls.size()+3, ')');
					for (int i=ls.size()-4; i>=0; --i)
						ls[i+2]=ls[i];
					ls[0]='~';
					ls[1]='(';
				}
//				if (rneg){	//bugged
//					rs.resize(rs.size()+3, ')');
//					for (int i=rs.size()-4; i>=0; --i)
//						rs[i+2]=rs[i];
//					rs[0]='~';
//					rs[1]='(';
//				}
				
				s= "((~("+ls+")^~("+rs+"))|(("+ls+")^("+rs+")))"; // limit connectives to ^ and |
				build(s, wff);	// p<>q = (~p^~q)|(p^q)
				return;
			}
			
			left= new formula;
			right= new formula;
			left->build(ls, wff);
			right->build(rs, wff);
			if (lneg)
				left->negated= !left->negated;
//			if (rneg)	//bugged
//				right->negated= !right->negated;
			
			if (con=='>'){
				con='|'; // limit connectives to ^ and |
				left->negated= !left->negated; // p>q = ~p|q
			}
		}
	}
};

void testprint (formula &f){ // for test and debug
	if (f.negated)
		printf("~");
		
	if (f.atomic){
		printf("%c", f.v);
	}
	else {
		printf("(");
		testprint (*(f.left));
		printf(" %c ", f.con);
		testprint (*(f.right));
		printf(")");
	}
}

void noRedundantNegation (formula &f){
	if (!f.atomic){
		if (f.negated){
			f.negated=false;
			if (f.con=='^')
				f.con='|';
			else // f.con == '|'
				f.con='^';
			
			f.left->negated=!f.left->negated;
			f.right->negated=!f.right->negated;
		}
		
		noRedundantNegation(*(f.left));
		noRedundantNegation(*(f.right));
	}
}

vvl convertToDNF (formula &f){
	vvl dnf;
	vl tempclause;
	lit templiteral;
	
	if (f.atomic){
		templiteral.c=f.v;
		templiteral.negated=f.negated;
		tempclause.push_back(templiteral);
		dnf.push_back(tempclause);
	}
	else {
		vvl ldnf, rdnf;
		ldnf= convertToDNF (*(f.left));
		rdnf= convertToDNF (*(f.right));
		
		if (f.con=='|'){
			dnf= ldnf;
			dnf.insert(dnf.end(), rdnf.begin(), rdnf.end());
		}
		else { // f.con=='^'
			int lsize= ldnf.size(), rsize= rdnf.size();
			for (int i=0; i<lsize; ++i)
				for (int j=0; j<rsize; ++j){
					tempclause= ldnf[i];
					tempclause.insert(tempclause.end(), rdnf[j].begin(), rdnf[j].end());
					dnf.push_back(tempclause);
				}
		}
	}
	
	return dnf;
}

void cleanDNF (vvl &dnf){
	int size= dnf.size();
	for (int i=0; i<size; ++i){
		sort (dnf[i].begin(), dnf[i].end());
//		unique (dnf[i].begin(), dnf[i].end()); // didn't work :-?
		for (int j=0; j<dnf[i].size()-1; ++j){
			while (j<dnf[i].size()-1 && dnf[i][j]==dnf[i][j+1]){
				dnf[i].erase(dnf[i].begin()+j+1);
			}
		}
	}
	
	sort (dnf.begin(), dnf.end());
//	unique (dnf.begin(), dnf.end()); //didn't work :-?
	for (int i=0; i<dnf.size()-1; ++i){
		while (i<dnf.size()-1 && dnf[i]==dnf[i+1]){
			dnf.erase(dnf.begin()+i+1);
		}
	}
	
	for (int i=0; i<dnf.size(); ++i){ 	// elimination of clauses which are contradiction
		int csize= dnf[i].size();
		for (int j=1; j<csize; ++j){
			if (dnf[i][j-1]!=dnf[i][j]) { // paradox
				dnf.erase(dnf.begin()+i); // removed
				--i;
				break;
			}
		}
	}
	
}

void remStrongClause (vvl &dnf){ 	// elimination of stronger clauses
	int size=dnf.size();
	vector<bool> isin(size, true);
	for (int i=0; i<size-1; ++i){
		if (isin[i])
			for (int j=i+1; j<size; ++j){
				bool removes= true;
				int fi=0, si=0, fsize=dnf[i].size(), ssize=dnf[j].size();
				while (fi<fsize){
					bool found= false;
					while (si<ssize){
						if (dnf[i][fi].c == dnf[j][si].c){
							if (dnf[i][fi] == dnf[j][si]){ // same literal found
								found= true;
								++si;
							}
							else { // negated found
								removes= false;
							}
							break;
						}
						else if (dnf[i][fi].c < dnf[j][si].c){ // not found
							removes= false;
							break;
						}
						
						++si;
					}
					
					if (!found)
						removes= false;
					
					++fi;
					if (fsize-fi > ssize-si){ 	// not sufficient literal left in dnf[j]
						removes= false;
					}
					if (!removes)
						break;
				}
				
				if (removes)
					isin[j]=false;
			}
	}
	for (int i=size-1; i>=0; --i)
		if (!isin[i])
			dnf.erase(dnf.begin()+i);
			
//	for (int i=0; i<size; ++i) //test ...
//		cout<<isin[i]<<" ";
//	cout<<endl;

}

void printDNF (vvl &dnf){
	int size= dnf.size(), csize;
	if (size==0){
		printf("The generated DNF is reduced to nothing;\nthe formula must've been a contradiction!\n");
		return;
	}
	
	for (int i=0; i<size; ++i){
		printf("(");
		csize= dnf[i].size();
		for (int j=0; j<csize; ++j){
			if (dnf[i][j].negated)
				printf("~");
			printf("%c", dnf[i][j].c);
			
			if (j<csize-1)
				printf(" ^ ");
		}
		printf(")");
		
		if (i<size-1)
			printf(" | ");
	}
	
	printf("\n");
}

bool sufPar (string &s){
	bool ande=false, ore=false, impe=false, iffe=false;
	int sum=0, size= s.size();
	
	for (int i=0; i<size; ++i){
		switch (s[i]){
			case '^':
				if (!ande){
					ande=true;
					++sum;
				}
				break;
			case '|':
				if (!ore){
					ore=true;
					++sum;
				}
				break;
			case '>':
				if (impe){
					return false;
				}
				else {
					impe=true;
					++sum;
				}
				break;
			case '=':
				if (iffe){
					return false;
				}
				else {
					iffe=true;
					++sum;
				}
				break;
			case '(':
				{
					int lend=rightPar(s, i);
					string st= s.substr(i+1, lend-i-1);
					if (!sufPar (st))
						return false;
					i=lend;
				}
		}
		
		if (sum>1)
			return false;
	}
	
	return true;
}


void DNFtoCNF (const vvl &dnf, vvl &cnf){
	cnf.clear();
	int csize= dnf[0].size();
	vl tc;
	for (int i=0; i<csize; ++i){
		tc.clear();
		tc.push_back(dnf[0][i]);
		cnf.push_back(tc);
	}
		
		
	vvl tcnf, * tcnfp, * cnfp;
	cnfp= &cnf;
	tcnfp= &tcnf;
	int size= dnf.size();
	for (int i=1; i<size; ++i){
		tcnfp->clear();
		csize= dnf[i].size();
		
		int cnfsize= cnfp->size();
		for (int j=0; j<cnfsize; ++j){
			for (int p=0; p<csize; ++p){
				tcnfp->push_back((*cnfp)[j]);
				((*tcnfp)[(tcnfp->size())-1]).push_back(dnf[i][p]);
			}
		}
		swap(cnfp, tcnfp);
	}
	
	if (cnfp!=&cnf)
		cnf= *cnfp;
}

void printCNF (vvl &cnf){
	int size= cnf.size(), csize;
	if (size==0){
		printf("The generated CNF is reduced to nothing;\nthe formula must've been a tautology!\n");
		return;
	}
	
	for (int i=0; i<size; ++i){
		printf("(");
		csize= cnf[i].size();
		for (int j=0; j<csize; ++j){
			if (cnf[i][j].negated)
				printf("~");
			printf("%c", cnf[i][j].c);
			
			if (j<csize-1)
				printf(" | ");
		}
		printf(")");
		
		if (i<size-1)
			printf(" ^ ");
	}
	
	printf("\n");
}


int main(){
	string s, st;
	formula f;
	vvl dnf;
	bool wff;
	char c;
	
	printf("DNF Generator\n\n");
	printf("Input constraints:\nUse parentheses to specify precedence.\n");
	printf("Use ^ to indicate conjunction, | for disjunction,\n");
	printf("> for implication, = for iff and ~ for negation.\n");
	printf("All the variables must be a single character.\n");
	printf("Every character out of the set { ~, (, ), ^, |, >, = }\n");
	printf("will be treated as a variable.\n");
	printf("Input will be case-sensitive.\n");
	
	int t=1;
	while (t==1){
		s.clear();
		f.clear();
		wff= true;
		
		printf("\nEnter a well-formed formula in a single line:\n");
		while ((c=getchar())!='\n'){
			if (!isspace(c)){
				if (c==')' && !s.empty() && s[s.size()-1]=='(') // skip empty parentheses
					s.resize(s.size()-1);
				else if (c=='~' && !s.empty() && s[s.size()-1]=='~')
					s.resize(s.size()-1);
				else
					s.push_back(c);
			}
		}
		st=s;
		
		f.build(s, wff);
		if (wff && !sufPar(st)){
			printf("\nThe formula lacks some necessary parentheses to specify precedence.\n");
			printf("Please try again.");
			continue;
		}
		if (!wff){
			printf("\nThe formula you entered is not well-formed.\n");
			printf("(whether it is against the stated constraints or has other syntactic errors.)\n");
			printf("Please try again.");
			continue;
		}
		
		noRedundantNegation(f);
		printf("\nThis equivalent formula is stored instead of yours:\n");
		testprint(f);
		printf("\n");
		
		dnf= convertToDNF (f);
		printf("\nThe following foumula is the raw generated DNF:\n");
		printDNF (dnf);
		
		printf("\nAfter some clean-up:\n");
		cleanDNF (dnf);
		printDNF (dnf);
		
		if (!dnf.empty()){
			printf ("\nAfter elimination of clauses which are stronger than another one:\n");
			remStrongClause (dnf);
			printDNF (dnf);
		}
		
		if (dnf.size()!=0){
			vvl cnf;
			DNFtoCNF (dnf, cnf);
			cleanDNF (cnf); // works for CNF too :)
			remStrongClause (cnf); // also this (?), equal to something like remWeakClause (CNF)
			printf("\nAnd that DNF converted to CNF:\n");
			printCNF (cnf);
		}
		
		printf("\n----------------------------------------------");
		printf("\nTo try again enter 1, any other number to exit: ");
		cin>>t;
		getchar();
	}
		
	return 0;
}
