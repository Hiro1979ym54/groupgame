#pragma once

class SceneGameOver {
private:
	
public:
	SceneGameOver();
	~SceneGameOver();

	void InitGameOver();		// ゲームオーバー初期化

	void StepGameOver();		// ゲームオーバー通常処理

	void DrawGameOver();		// ゲームオーバー描画処理

	void FinGameOver();		    // ゲームオーバー終了処理
};