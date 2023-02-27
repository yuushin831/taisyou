#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() 
{
	delete spritesong_;
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	debugText_ = DebugText::GetInstance();

	textureHandleSong_ = TextureManager::Load("0001.png");
	spritesong_ = Sprite::Create(textureHandleSong_, { 860,360 });

	worldTransform_.Initialize();
}

void GameScene::Update() 
{
	Vector2 p = spritesong_->GetPosition();
	/*DirectX position_{};
	position_.x *= p.x;
	position_.y *= p.y;*/

	if (input_->TriggerKey(DIK_D))
	{
		p.x += 300.0f;

	}
	if (input_->TriggerKey(DIK_A))
	{
		p.x -= 300.0f;
	}
	/*if (input_->PushKey(DIK_S))
	{
		p.y += 10.0f;
	}
	if (input_->PushKey(DIK_W))
	{
		p.y -= 10.0f;
	}*/
	spritesong_->SetPosition(p);

	debugText_->Printf("%f",p.x);
	debugText_->SetPos(0, 15);
	debugText_->Printf("%f",p.y);
	debugText_->SetPos(0, 30);

	worldTransform_.TransferMatrix();
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>
	spritesong_->Draw();

	// デバッグテキストの描画
	debugText_->DrawAll(commandList);
	//
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
