# 応用実験軌道生成ツール
弊学の応用実験で配布されたエクセルシートを編集することなくマニピュレータの軌道を生成できるツールです  
いまのところUbuntu、MacOSでの動作を確認しています  
Windowsだと文字化けします
## 使い方
1 ターミナルを開き、プログラムが入っているディレクトリ直下に移動する  
2 ./calc_routeと入力  
3 ターミナルの表示に従って数値を入力する
## 使用上の注意
・時刻の単位はすべて秒、長さ・座標の単位はすべてmmです。小数点以下第2位まで指定可能です  
・出力先のパスはファイルを出力したいディレクトリ・ファイル名のフルパスを入力してください  
・ファイル出力する際に_deg1.csv、_deg2.csvは自動で付け加えられるのでその手前まで入力するようにしてください  
 例(デスクトップ上にoutputという名前で出力する場合): /Users/\[ユーザー名\]/Desktop/output  
 例のように入力するとデスクトップ上にoutput_deg.csv、output_deg1.csv、output_deg2.csvというファイルが生成されます。  
  \_deg.csvは実機用で、\_deg1.csv及び  \_deg2.csvはSolidWorksでのモーション解析用です。  
    \_deg1.csvはθ1、\_deg2.csvはθ2の出力ファイルです。  
## ビルド
`g++ -Ofast -o hoge *.cpp *.hpp`   
`./hoge`
## 座標等定義
座標等の定義は下の図の通りです。  
![座標系等定義](https://user-images.githubusercontent.com/57407826/70992095-3cb46180-210c-11ea-89bb-fb063a3ec047.jpg)
