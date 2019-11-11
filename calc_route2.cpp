#include "calc_route.hpp"

void calc_route2(){
    double sx,sy,ex,ey,x,y,deg1,deg2;
    double xt0,xt1,xt2,xt3,yt0,yt1,yt2,yt3;
    double xt,yt;
    double t_all=0;
    vector<double> T(6);//各区間の加速終了・減速開始時刻
    vector<vector<double>>C(4,vector<double>(2));//各コーナーの座標
    double t; //t0: 加速終了時刻, t1: 減速開始時刻
    int i,i_finish;
    double L1,L2;
    double d1,d2;
    string output_path;
    ofstream write_deg1,write_deg2;

    cout<<"第1区間加速終了時刻を入力してください: ";
    cin>>T[0];
    cout<<"第1区間減速開始時刻を入力してください: ";
    cin>>T[1];
    cout<<"第2区間加速終了時刻を入力してください: ";
    cin>>T[2];
    cout<<"第2区間減速開始時刻を入力してください: ";
    cin>>T[3];
    cout<<"第3区間加速終了時刻を入力してください: ";
    cin>>T[4];
    cout<<"第3区間減速開始時刻を入力してください: ";
    cin>>T[5];

    cout<<"スタート地点のx座標、y座標をそれぞれスペースで区切って入力してください: ";
    cin>>C[0][0]>>C[0][1];
    cout<<"第1コーナーのx座標、y座標をそれぞれスペースで区切って入力してください: ";
    cin>>C[1][0]>>C[1][1];
    cout<<"第2コーナーのx座標、y座標をそれぞれスペースで区切って入力してください: ";
    cin>>C[2][0]>>C[2][1];
    cout<<"ゴール地点のx座標、y座標をそれぞれスペースで区切って入力してください: ";
    cin>>C[3][0]>>C[3][1];
    cout<<"リンク1の長さを入力してください: ";
    cin>>L1;
    cout<<"リンク2の長さを入力してください: ";
    cin>>L2;

    T[4]-=T[2]+T[3]-T[1]-T[0];
    T[5]-=T[2]+T[3]-T[1]-T[0];
    T[2]-=T[0]+T[1];
    T[3]-=T[0]+T[1];

    for(i=0;i<6;i++){
        t_all+=100*T[i];
    }
    i_finish=(int)t_all;

    //cout<<T[0]<<" "<<T[1]<<" "<<T[2]<<" "<<T[3]<<" "<<T[4]<<" "<<T[5]<<endl;
    
    cout<<"出力先のパス(ファイル名含む)を入力してください: ";
    cin>>output_path;
    write_deg1.open(output_path+"_deg1.csv",ios::out);
    write_deg2.open(output_path+"_deg2.csv",ios::out);

    for(i=0;i<=i_finish;i++){
        t=(double)i/(double)100;
        //スタート~第1コーナー
        if(t<=T[0]){
            x=C[0][0]+(C[1][0]-C[0][0])/T[0]/T[1]/2*t*t;
            y=C[0][1]+(C[1][1]-C[0][1])/T[0]/T[1]/2*t*t;
            if(t==T[0]){
                xt=x;
                yt=y;
            }
        }else if(t<=T[1]){
            x=xt+(C[1][0]-C[0][0])/T[1]*(t-T[0]);
            y=yt+(C[1][1]-C[0][1])/T[1]*(t-T[0]);
            if(t==T[1]){
                xt=x;
                yt=y;
            }
        }else if(t<=T[0]+T[1]){
            x=xt+0.5*(C[1][0]-C[0][0])/T[1]*(T[0]-(T[1]+T[0]-t)*(T[1]+T[0]-t)/T[0]);
            y=yt+0.5*(C[1][1]-C[0][1])/T[1]*(T[0]-(T[1]+T[0]-t)*(T[1]+T[0]-t)/T[0]);
            if(t==T[0]+T[1]){
                xt=x;
                yt=y;
                /*cout<<endl;
                cout<<xt<<endl;
                cout<<yt<<endl;
                cout<<endl;*/
            }
        }else if(t>=T[0]+T[1] && t<T[0]+T[1]+T[2]+T[3]){
            //第1コーナー~第2コーナー
            t-=T[0]+T[1];
            if(t<=T[2]){
                x=C[1][0]+(C[2][0]-C[1][0])/T[2]/T[3]/2*t*t;
                y=C[1][1]+(C[2][1]-C[1][1])/T[2]/T[3]/2*t*t;
                if(t==T[2]){
                    xt=x;
                    yt=y;
                }
            }else if(t<=T[3]){
                x=xt+(C[2][0]-C[1][0])/T[3]*(t-T[2]);
                y=yt+(C[2][1]-C[1][1])/T[3]*(t-T[2]);
                if(t==T[3]){
                    xt=x;
                    yt=y;
                }
            }else if(t<=T[2]+T[3]){
                x=xt+0.5*(C[2][0]-C[1][0])/T[3]*(T[2]-(T[3]+T[2]-t)*(T[3]+T[2]-t)/T[2]);
                y=yt+0.5*(C[2][1]-C[1][1])/T[3]*(T[2]-(T[3]+T[2]-t)*(T[3]+T[2]-t)/T[2]);
                if(t==T[2]+T[3]){
                    xt=x;
                    yt=y;
                    /*cout<<endl;
                    cout<<xt<<endl;
                    cout<<yt<<endl;
                    cout<<endl;*/
                }
            }
        }else if(t>=T[0]+T[1]+T[2]+T[3]){
            //第2コーナー~ゴール
            t-=T[0]+T[1]+T[2]+T[3];
            if(t<=T[4]){
                x=C[2][0]+(C[3][0]-C[2][0])/T[4]/T[5]/2*t*t;
                y=C[2][1]+(C[3][1]-C[2][1])/T[4]/T[5]/2*t*t;
                if(t==T[4]){
                    xt=x;
                    yt=y;
                }
            }else if(t<=T[5]){
                x=xt+(C[3][0]-C[2][0])/T[5]*(t-T[4]);
                y=yt+(C[3][1]-C[2][1])/T[5]*(t-T[4]);
                if(t==T[5]){
                    xt=x;
                    yt=y;
                }
            }else if(t<=T[4]+T[5]){
                x=xt+0.5*(C[3][0]-C[2][0])/T[5]*(T[4]-(T[5]+T[4]-t)*(T[5]+T[4]-t)/T[4]);
                y=yt+0.5*(C[3][1]-C[2][1])/T[5]*(T[4]-(T[5]+T[4]-t)*(T[5]+T[4]-t)/T[4]);
                if(t==T[4]+T[5]){
                    xt=x;
                    yt=y;
                    /*cout<<endl;
                    cout<<xt<<endl;
                    cout<<yt<<endl;
                    cout<<endl;*/
                }
            }
        }
        //cout<<t<<" "<<x<<" "<<y<<endl;
        d1=(atan2(y,x)-acos((x*x+y*y+L1*L1-L2*L2)/(2*sqrt(x*x+y*y)*L1)))*180/M_PI;
        d2=180-180/M_PI*acos((L1*L1+L2*L2-x*x-y*y)/(2*L1*L2));

        write_deg1<<(double)i/(double)100<<","<<fixed<<setprecision(5)<<d1<<endl;
        write_deg2<<(double)i/(double)100<<","<<fixed<<setprecision(5)<<d2<<endl;
    }
}