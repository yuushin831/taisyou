#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "DebugText.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include<DirectXMath.h>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

  public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

  private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	DebugText* debugText_ = nullptr;
	WorldTransform worldTransform_;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
	
	//枠
	uint32_t textureHandleFrame_ = 0;
	Sprite* spriteframe_ = nullptr;
	//1
	uint32_t textureHandleSong_ = 0;
	Sprite* spritesong_ = nullptr;
	//2
	uint32_t textureHandleSong2_ = 0;
	Sprite* spritesong2_ = nullptr;
	//3
	uint32_t textureHandleSong3_ = 0;
	Sprite* spritesong3_ = nullptr;
	//4
	uint32_t textureHandleSong4_ = 0;
	Sprite* spritesong4_ = nullptr;
	//5
	uint32_t textureHandleSong5_ = 0;
	Sprite* spritesong5_ = nullptr;
	
	//BG
	uint32_t textureHandleBG_ = 0;
	Sprite* spriteBG_ = nullptr;
};
