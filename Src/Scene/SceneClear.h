#pragma once

class SceneClear {
private:

public:
	SceneClear();
	~SceneClear();

	void InitClear();		// クリア初期化

	void StepClear();		// クリア通常処理

	void DrawClear();		// クリア描画処理

	void FinClear();		//クリア終了処理

};
