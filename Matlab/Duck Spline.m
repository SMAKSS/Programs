close all
clear all
clc
% %  WAIST 
w=-7:.1:1;
    ww=(12*sin(w-7.5)./(w-7.5))-1;
www=-7:2:1;
    wwww=spline(w,ww,www);
subplot(3,1,1);
plot(w,ww)
title('WAIST')
subplot(3,1,2);
plot(w,ww,www,wwww,'o')
subplot(3,1,3);
plot(w,ww,www,wwww,':')
figure

R = .4;
angle = -1.7:2*pi/50:1;
    n = 1+.5*4*R*cos(angle);  nn = 0.3+R*2*sin(angle);
    
R = .4;
angle = -1.7:1;    
    j = 1+.5*4*R*cos(angle);   jj= 0.3+R*2*sin(angle);
% nnn=-1.7:1;
%     nnnn=spline(angle,nn,nnn);
% plot(w,ww)
% figure
% % NECK
e=1:.1:9;
    ee=.05*((e-4).^2)+1;
eee=1:2:9;
    eeee=spline(e,ee,eee);
subplot(3,1,1);    
plot(ee,e)
title('NECK')
subplot(3,1,2);
plot(ee,e,eeee,eee,'o')
subplot(3,1,3);
plot(ee,e,eeee,eee,':')
figure
    
f=1.8:.1:6.3;
    ff=.2*((f-4).^2)+2.5;
fff=1.8:6.3;
    ffff=spline(f,ff,fff);
% subplot(3,1,1);    
% plot(ff,f)
% title('NECK')
% subplot(3,1,2);
% plot(ff,f,ffff,fff,'o')
% subplot(3,1,3);
% plot(ff,f,ffff,fff,':')
% figure
%     
% %  HEAD
t=2:.1:4;
    tt=-((t-3).^2)+9.5;
ttt=2:4;
    tttt=spline(t,tt,ttt);
% subplot(3,1,1);
% plot(t,tt)
% title('HEAD')
% subplot(3,1,2);
% plot(t,tt,ttt,tttt,'o')
% subplot(3,1,3);
% plot(t,tt,ttt,tttt,':')
% figure
    
k=6.2:.001:7;
    kk=-(4*(k-6.8).^2)+4.9;
kkk=6.2:.5:7;
    kkkk=spline(k,kk,kkk);
% subplot(3,1,1);
% plot(kk,k)
% title('HEAD')
% subplot(3,1,2);
% plot(kk,k,kkkk,kkk,'o')
% subplot(3,1,3);
% plot(kk,k,kkkk,kkk,':')
% figure
    
l=6.7:.001:8.5;
    ll=-(2*(l-7.6).^2)+5.6;
lll=6.7:.4:8.5;
    llll=spline(l,ll,lll);
subplot(3,1,1);
plot(ll,l)
title('HEAD')
subplot(3,1,2);
plot(ll,l,llll,lll,'o')
subplot(3,1,3);
plot(ll,l,llll,lll,':')
figure    
    
p=6.7:.1:8.7;
    pp=.05*((p-7).^2)+3.8;
ppp=6.7:8.7;
    pppp=spline(p,pp,ppp);
% subplot(3,1,1);
% plot(pp,p)
% title('HEAD')
% subplot(3,1,2);
% plot(pp,p,pppp,ppp,'o')
% subplot(3,1,3);
% plot(pp,p,pppp,ppp,':')
% figure    
%     
R = .1;                            
angle = 0:2*pi/50:2*pi;            
    g = 4.1+.5*R*cos(angle);  gg = 7.7+R*sin(angle);
ggg=0:2*pi;
%     gggg=spline(g,gg,ggg);
% %  Stomach

h=-7:.1:2.5;
    hh=.2*((h).^2)-10;
hhh=-7:3:2.5;
    hhhh=spline(h,hh,hhh);
subplot(3,1,1);
plot(h,hh)
title('STOMACH')
subplot(3,1,2);
plot(h,hh,hhh,hhhh,'o')
subplot(3,1,3);
plot(h,hh,hhh,hhhh,':')
figure 
    
%  plot(w,ww,h,hh)
%   figure

a=-9:.1:2;
    aa=-.05*((a+2.5).^2)+4.4;
aaa= -9:2:2;
    aaaa=spline(a,aa,aaa);
% subplot(3,1,1);
% plot(aa,a)
% title('')
% subplot(3,1,2);
% plot(aa,a,aaaa,aaa,'o')
% subplot(3,1,3);
% plot(aa,a,aaaa,aaa,':')
% figure
    
% %  circle eye 
R = .2;                            % Unit radius
angle = 0:2*pi/50:2*pi;            % vector of angles at which points are drawn
    x = 2.9+.5*R*cos(angle);  xx = 7.9+R*sin(angle);   % Coordinates of circle
% xxx=0:2*pi;
%     xxxx=spline(angle,x,xx);
R = .2;
angle = 0:2*pi;
    b = 2.9+.5*R*cos(angle);  bb = 7.9+R*sin(angle);
    
% subplot(3,1,1);
% plot(x,xx)
% title('EYE')
% subplot(3,1,2);
% plot(x,xx,b,bb,'o')
% subplot(3,1,3);
% plot(x,xx,b,bb,':')
% figure    
    
R = .3;                            
angle = 0:2*pi/50:2*pi;            
    y = 2.9+.5*R*cos(angle);  yy = 7.9+R*sin(angle);
% yyy = 0:2*pi;
%     yyyy=spline(y,yy,yyy);
R = .3;
angle = 0:2*pi;            
     c= 2.9+.5*R*cos(angle);  cc = 7.9+R*sin(angle);
     
% subplot(3,1,1);
% plot(y,yy)
% title('EYE')
% subplot(3,1,2);
% plot(y,yy,c,cc,'o')
% subplot(3,1,3);
% plot(y,yy,c,cc,':')
% figure     
    
R = .5;                            
angle = 0:2*pi/50:2*pi;            
     z = 3+.5*R*cos(angle);  zz = 8+R*sin(angle);
% zzz = 0:2*pi;
%     zzzz=spline(z,zz,zzz);
R = .5;                            
angle = 0:2*pi;            
     i = 3+.5*R*cos(angle);  ii = 8+R*sin(angle);
     
subplot(3,1,1);
plot(z,zz)
title('EYE')
subplot(3,1,2);
plot(z,zz,i,ii,'o')
subplot(3,1,3);
plot(z,zz,i,ii,':')
figure

% % %  LEG
% r=.2:.1:1.2;
%     rr=-4*r-9;
% rrr=.2:.1:1.2;
%     rrrr=spline(r,rr,rrr);
% b=0:.1:1;
%     bb=-4*b-9;
% bbb=0:.1:1;
%     bbbb=spline(b,bb,bbb);
% c=1.2:.1:2.2;
%     cc=-.6*c-13.6;
% ccc=0:.1:1;
%     cccc=spline(c,cc,ccc);
% u=1:.1:2;
%     uu=-2*u-13.4;
   
% uuu=0:.1:1;
%     uuuu=spline(u,uu,uuu);
% m=1:.01:1;
%     mm=5*(r)-15.4;
% aaa= -9:2;
% v=-1:.1:0;
%     vv=-(v+5).^2;
% ppp=6.7:8.7;
%     pppp=spline(p,pp,ppp);    
% rrr=6.7:8.7;
%     rrrr=spline(r,rr,rrr);

% % WING
v=-4.7:.1:1;
    vv=.1*((v).^2)-6.5;
vvv=-4.8:1;    
    vvvv=spline(v,vv,vvv);
% subplot(3,1,1);
% plot(v,vv)
% title('WING')
% subplot(3,1,2);
% plot(v,vv,vvv,vvvv,'o')
% subplot(3,1,3);
% plot(v,vv,vvv,vvvv,':')
% figure    
    
d=-4.7:.1:-.5;
    dd=-.1*((d).^2)-2;
ddd=-4.8:-.5;    
    dddd=spline(d,dd,ddd);
subplot(3,1,1);
plot(d,dd)
title('WING')
subplot(3,1,2);
plot(d,dd,ddd,dddd,'o')
subplot(3,1,3);
plot(d,dd,ddd,dddd,':')
figure
    
% %  PLOT
plot(w,ww,aa,a,ee,e,ff,f,h,hh,x,xx,y,yy,z,zz,t,tt,kk,k,ll,l,n,nn,pp,p,g,gg,v,vv,d,dd);
figure
subplot(2,1,1);
  plot(w,ww,aa,a,ee,e,ff,f,h,hh,x,xx,y,yy,z,zz,t,tt,kk,k,ll,l,n,nn,pp,p,g,gg,v,vv,d,dd);
  title('(1)')
subplot(2,1,2);
   plot (w,ww,www,wwww,'p',aa,a,aaaa,aaa,'p',ee,e,eeee,eee,'p',ff,f,ffff,fff,'p',j,jj,'p',h,hh,hhh,hhhh,'p',i,ii,'p',t,tt,ttt,tttt,'p',kk,k,kkkk,kkk,'p',b,bb,'p',ll,l,llll,lll,'p',pp,p,pppp,ppp,'p',v,vv,vvv,vvvv,'p',d,dd,ddd,dddd,'p');
   title('(2)')
   figure
subplot(2,1,1);
    plot (www,wwww,'p',aaaa,aaa,'p',eeee,eee,'p',ffff,fff,'p',j,jj,'p',hhh,hhhh,'p',ttt,tttt,'p',b,bb,'p',kkkk,kkk,'p',i,ii,'p',llll,lll,'p',pppp,ppp,'p',vvv,vvvv,'p',ddd,dddd,'p');
    title('(3)')
subplot(2,1,2);
    plot (www,wwww,aaaa,aaa,eeee,eee,ffff,fff,hhh,hhhh,ttt,tttt,b,bb,j,jj,c,cc,i,ii,kkkk,kkk,llll,lll,pppp,ppp,vvv,vvvv,ddd,dddd);
    title('(4)')