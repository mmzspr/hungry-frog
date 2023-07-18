# hungry-frog
木をよけながら蝶々をたべてスコアを稼ごう🦋

### デモ動画
https://github.com/mmzspr/hungry-frog/assets/30862527/4107bd9c-3f65-48cf-9b91-736a2c082a26

### 実装上の特徴
- 可能な限り3Dグラフィックスの描画処理を手実装しました
  - 3Dオブジェクト(カエル・地形)は全てDXライブラリの平面画像の描画関数（[DrawModiGraph](https://dixq.net/g/04_02.html)）を用いて表現しています
  - 陰面除去
  - シェーディング処理
  - カエルの3Dモデルは人力で座標をプロッティングして作成しました
    https://github.com/mmzspr/hungry-frog/blob/0590dbc34b1494ec4f59af4519160f3ef0284d46/struct.h#L119-L130
- 地形はパーリンノイズを用いて自動生成しています

### 音源素材
- 秋山裕和『二人の旅人』(フリー音楽素材 H/MIX GALLERY, http://www.hmix.net/)
