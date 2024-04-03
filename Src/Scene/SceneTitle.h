#pragma once

//タイトルクラス
class SceneTitle {
private:
	//画像用変数
	int BackHan = 0;
	int GroundHan = 0;
public:
	SceneTitle();
	~SceneTitle();

	void InitTitle();		// タイトル初期化

	void StepTitle();		// タイトル通常処理

	void DrawTitle();		// タイトル描画処理

	void FinTitle();		// タイトル終了処理
};