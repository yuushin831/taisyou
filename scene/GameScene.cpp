#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() 
{
	delete spritesong_;
	delete spritesong2_;
	delete spritesong3_;
	delete spritesong4_;
	delete spritesong5_;
	//delete spritesong6_;
	delete spriteframe_;
	delete spriteBG_;
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	debugText_ = DebugText::GetInstance();
	//枠
	textureHandleFrame_ = TextureManager::Load("000.png");
	spriteframe_ = Sprite::Create(textureHandleFrame_, { 850,349 });
	//1
	textureHandleSong_ = TextureManager::Load("0001.png");
	spritesong_ = Sprite::Create(textureHandleSong_, { 860,360 });
	//2
	textureHandleSong2_ = TextureManager::Load("0002.png");
	spritesong2_ = Sprite::Create(textureHandleSong2_, { 1160,360 });
	//3
	textureHandleSong3_ = TextureManager::Load("0003.png");
	spritesong3_ = Sprite::Create(textureHandleSong3_, { 1460,360 });
	//4
	textureHandleSong4_ = TextureManager::Load("0004.png");
	spritesong4_ = Sprite::Create(textureHandleSong4_, { 560,360 });
	//5
	textureHandleSong5_ = TextureManager::Load("0005.png");
	spritesong5_ = Sprite::Create(textureHandleSong5_, { 260,360 });
	//BG
	textureHandleBG_ = TextureManager::Load("moyou01.png");
	spriteBG_ = Sprite::Create(textureHandleBG_, { 0,0 });
	

	worldTransform_.Initialize();
}

void GameScene::Update() 
{
	//------------------------------1-------------------------
	Vector2 p = spritesong_->GetPosition();
	if (input_->TriggerKey(DIK_D))
	{
		p.x += 300.0f;
		

	}
	if (input_->TriggerKey(DIK_A))
	{
		p.x -= 300.0f;
		
	}
	if (p.x == -340)
	{
		p.x = 1760;
	}
	
	spritesong_->SetPosition(p);
	//------------------------------2-------------------------
	Vector2 p2 = spritesong2_->GetPosition();
	if (input_->TriggerKey(DIK_D))
	{
		
		p2.x += 300.0f;

	}
	if (input_->TriggerKey(DIK_A))
	{
		
		p2.x -= 300.0f;
	}
	if (p2.x == -340)
	{
		p2.x = 1760;
	}
	spritesong2_->SetPosition(p2);
	//------------------------------2-------------------------
	Vector2 p3 = spritesong3_->GetPosition();
	if (input_->TriggerKey(DIK_D))
	{

		p3.x += 300.0f;

	}
	if (input_->TriggerKey(DIK_A))
	{

		p3.x -= 300.0f;
	}
	if (p3.x == -340)
	{
		p3.x = 1760;
	}
	spritesong3_->SetPosition(p3);
	//------------------------------4-------------------------
	Vector2 p4 = spritesong4_->GetPosition();
	if (input_->TriggerKey(DIK_D))
	{

		p4.x += 300.0f;

	}
	if (input_->TriggerKey(DIK_A))
	{

		p4.x -= 300.0f;
	}
	if (p4.x == -340)
	{
		p4.x = 1760;
	}
	spritesong4_->SetPosition(p4);
	//------------------------------5-------------------------
	Vector2 p5 = spritesong5_->GetPosition();
	if (input_->TriggerKey(DIK_D))
	{

		p5.x += 300.0f;

	}
	if (input_->TriggerKey(DIK_A))
	{

		p5.x -= 300.0f;
	}
	if (p5.x == -340)
	{
		p5.x = 1760;
	}
	spritesong5_->SetPosition(p5);
	//------------------------------6-------------------------
	/*Vector2 p6 = spritesong6_->GetPosition();
	if (input_->TriggerKey(DIK_D))
	{

		p6.x += 300.0f;

	}
	if (input_->TriggerKey(DIK_A))
	{

		p6.x -= 300.0f;
	}
	if (p6.x == -340)
	{
		p6.x = 1760;
	}
	spritesong5_->SetPosition(p6);*/
	//------------------------------7-------------------------

















	/*debugText_->Printf("%f",p.x);
	debugText_->SetPos(0, 15);
	debugText_->Printf("%f",p.y);
	debugText_->SetPos(0, 30);*/

	
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
	spriteBG_->Draw();
	spriteframe_->Draw();
	spritesong_->Draw();
	spritesong2_->Draw();
	spritesong3_->Draw();
	spritesong4_->Draw();
	spritesong5_->Draw();
	//spritesong6_->Draw();
	// デバッグテキストの描画
	debugText_->DrawAll(commandList);
	//
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
