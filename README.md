# MiniProject-B-Spline
Basic Project - 1st Year in DUT
Dự án này được xây dựng cho đồ án cơ sở của DUT
Dự án tính điểm B-Spline dựa trên những điều kiện đã được nhập sẵn

## プロジェクトの目的 
1年生のコースプロジェク

## プロジェクトの説明 
プロジェクトは、事前に入力された条件に基づいて B-spline スコアを計算

**入力**

-n、p、uの値。
-各i番目の頂点には、x[i]、y[i]、z[i]の3つの値が含まれています。
-u[i]値。

**出力** 

-点C（u）=（x、y、z）の座標は、B-spline 曲線のパラメーター 0≤u≤1 に対応します。 
## こだわりポイント
C ++言語で作成されたプロジェクト

ストレージと処理に動的配列データ構造を使用します

アルゴリズム：パラメーター u に対応する B-spline 曲線上の点を決定するために、多項式Ni、p(u）と多項式 C(u）の再帰計算を実装します
