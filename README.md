# 応用実験軌道生成ツール
弊学の応用実験で配布されたエクセルシートを編集することなくマニピュレータの軌道を生成できるツールです  
いまのところUbuntu、MacOSでの動作を確認しています  
Windowsだと文字化けします
## 使い方(Solid Worksでのシミュレーション)
1 ターミナルを開き、プログラムが入っているディレクトリ直下に移動する  
2 `./calc_route`と入力  
3 ターミナルの表示に従って数値を入力する

## 使い方(実機)
1 decide_dir.csvを実機に読み込ませ、動かす  
2 実機の回転方向に応じてcalc_route.hppを以下のように書き換える  
  リンク1が時計回り、リンク2が反時計回りのとき  
  `#define dir1 1`  
  `#define dir2 1`  
 </br>
 リンク1が時計回り、リンク2が反時計回りのとき  
  `#define dir1 1`  
  `#define dir2 -1`  
  </br>
 リンク1が反時計回り、リンク2が時計回りのとき  
  `#define dir1 -1`  
  `#define dir2 1`  
  </br>
 リンク1が反時計回り、リンク2が反時計回りのとき  
  `#define dir1 -1`  
  `#define dir2 -1`  
3 ビルドして実行する([ビルド](#ビルド)の項を参照)  
4 ターミナルの表示に従って数値を入力する
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
