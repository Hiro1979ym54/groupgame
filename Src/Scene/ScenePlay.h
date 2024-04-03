#pragma once

class ScenePlay {
private:

public:
	ScenePlay();
	~ScenePlay();

	void InitPlay();		// クリア初期化

	void StepPlay();		// クリア通常処理

	void DrawPlay();		// クリア描画処理

	void FinPlay();			//プレイ終了処理
};
