#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<string>
using namespace std;

int main(){
    double sx,sy,ex,ey,x,y,deg1,deg2;
    double xt0,xt1,xt2,xt3,yt0,yt1,yt2,yt3;
    double t0,t1,t2,t3,t; //t0: 加速終了時刻, t1: 減速開始時刻
    int i,i_finish;
    double L1,L2;
    double d1,d2;
    string output_path;
    ofstream write_deg1,write_deg2;

    cout<<"往路加速終了時刻を入力してください: ";
    cin>>t0;
    cout<<"往路減速開始時刻を入力してください: ";
    cin>>t1;
    cout<<"復路加速終了時刻を入力してください: ";
    cin>>t2;
    cout<<"復路減速開始時刻を入力してください: ";
    cin>>t3;

    cout<<"スタート地点のx座標、y座標をそれぞれスペースで区切って入力してください: ";
    cin>>sx>>sy;
    cout<<"ゴール地点のx座標、y座標をそれぞれスペースで区切って入力してください: ";
    cin>>ex>>ey;
    cout<<"リンク1の長さを入力してください: ";
    cin>>L1;
    cout<<"リンク2の長さを入力してください: ";
    cin>>L2;

    cout<<"出力先のパス(ファイル名含む)を入力してください: ";
    cin>>output_path;
    write_deg1.open(output_path+"_deg1.csv",ios::out);
    write_deg2.open(output_path+"_deg2.csv",ios::out);

    i_finish=(int)(100*t3+100*t2-100*t0-100*t1);

    for(i=0;i<=i_finish;i++){
        t=(double)i/(double)100;
        if(t<=t0){
            x=sx+(ex-sx)/t0/t1/2*t*t;
            y=sy+(ey-sy)/t0/t1/2*t*t;
            if(t==t0){
                xt0=x;
                yt0=y;
            }
        }else if(t<=t1){
            x=xt0+(ex-sx)/t1*(t-t0);
            y=yt0+(ey-sy)/t1*(t-t0);
            if(t==t1){
                xt1=x;
                yt1=y;
            }
        }else if(t<=t0+t1){
            x=xt1+0.5*(ex-sx)/t1*(t0-(t1+t0-t)*(t1+t0-t)/t0);
            y=yt1+0.5*(ey-sy)/t1*(t0-(t1+t0-t)*(t1+t0-t)/t0);
        }else if(t<=t2){
            x=ex+(sx-ex)/(t2-t0-t1)/(t3-t0-t1)/2*(t-t0-t1)*(t-t0-t1);
            y=ey+(sy-ey)/(t2-t0-t1)/(t3-t0-t1)/2*(t-t0-t1)*(t-t0-t1);
            if(t==t2){
                xt2=x;
                yt2=y;
            }
        }else if(t<=t3){
            x=xt2+(sx-ex)/(t3-t0-t1)*(t-t2);
            y=yt2+(sy-ey)/(t3-t0-t1)*(t-t2);
            if(t==t3){
                xt3=x;
                yt3=y;
            }
        }else if(t<=(double)i_finish/(double)100){
            x=xt3+0.5*(sx-ex)/(t3-t0-t1)*(t2-t0-t1-(t3+t2-t0-t1-t)*(t3+t2-t0-t1-t)/(t2-t0-t1));
            y=yt3+0.5*(sy-ey)/(t3-t0-t1)*(t2-t0-t1-(t3+t2-t0-t1-t)*(t3+t2-t0-t1-t)/(t2-t0-t1));
        }
        d1=(atan2(y,x)-acos((x*x+y*y+L1*L1-L2*L2)/(2*sqrt(x*x+y*y)*L1)))*180/M_PI;
        d2=180-180/M_PI*acos((L1*L1+L2*L2-x*x-y*y)/(2*L1*L2));

        write_deg1<<t<<","<<fixed<<setprecision(5)<<d1<<endl;
        write_deg2<<t<<","<<fixed<<setprecision(5)<<d2<<endl;
    }
}
