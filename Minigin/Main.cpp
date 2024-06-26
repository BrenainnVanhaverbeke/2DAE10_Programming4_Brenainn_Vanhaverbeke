#include "pch.h"
#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextObject.h"
#include "Scene.h"
#include "BaseComponent.h"
#include "RenderComponent.h"
#include "ImageComponent.h"
#include "TextComponent.h"
#include "FpsScript.h"
#include "FixedFpsScript.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_shared<dae::GameObject>();
	std::shared_ptr<dae::BaseComponent> imageComponent{ std::make_shared<dae::ImageComponent>("background.tga", go->GetTransform()) };
	//go->SetTexture("background.tga");
	go->AddComponent(imageComponent);
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->SetPosition(216, 180);
	imageComponent = std::make_shared<dae::ImageComponent>("logo.tga", go->GetTransform());
	//go->SetTexture("logo.tga");
	go->AddComponent(imageComponent);
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->SetPosition(80, 20);
	std::shared_ptr<dae::BaseComponent> textComponent{ std::make_shared<dae::TextComponent>("Programming 4 Assignment", "Lingua.otf", 36, go->GetTransform()) };
	go->AddComponent(textComponent);
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	textComponent = std::make_shared<dae::TextComponent>("0", "Lingua.otf", 12, go->GetTransform());
	std::shared_ptr<dae::BaseComponent> scriptComponent{ std::make_shared<dae::FpsScript>(go->GetTransform()) };
	go->AddComponent(textComponent);
	go->AddComponent(scriptComponent);
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->SetPosition(0, 20.f);
	textComponent = std::make_shared<dae::TextComponent>("0", "Lingua.otf", 12, go->GetTransform());
	scriptComponent = std::make_shared<dae::FixedFpsScript>(go->GetTransform());
	go->AddComponent(textComponent);
	go->AddComponent(scriptComponent);
	scene.Add(go);
}

int main(int, char* []) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
	return 0;
}