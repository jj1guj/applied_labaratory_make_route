#include "calc_route.hpp"

int main(){
    int choose;
    cout<<"直線軌道を生成する場合には1を、クランク軌道を生成する場合には2を入力してください:";
    cin>>choose;

    while(choose!=1 && choose!=2){
        cout<<"エラー"<<endl;
        cout<<"もう一度入力してください"<<endl;
        cout<<"直線軌道を生成する場合には1を、クランク軌道を生成する場合には2を入力してください:";
        cin>>choose;
    }

    if(choose==1){
        calc_route1();
    }else{
        calc_route2();
    }
}