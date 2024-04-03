#pragma once

//タイトルクラス
class SceneTitle {
private:
	//画像用変数
	int BackHan = 0;
	int GroundHan = 0;
	int titleHan = 0;

	//地面のスライド処理用変数
	int GroundPosX = 0;
	int GroundPosX2 = 1280;
public:
	SceneTitle();
	~SceneTitle();

	void InitTitle();		// タイトル初期化

	void StepTitle();		// タイトル通常処理

	void DrawTitle();		// タイトル描画処理

	void FinTitle();		// タイトル終了処理
};