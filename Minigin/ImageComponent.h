#pragma once
#include "RenderComponent.h"
#include <string>
#include <memory>

namespace dae
{
	class Texture2D;

	class ImageComponent final :
		public RenderComponent
	{
	public:
		ImageComponent(std::string sourcePath, Transform& parentTransform, int zIndex = 0);
		ImageComponent(std::string sourcePath, Transform& parentTransform, const Transform& transform, int zIndex = 0);
		virtual ~ImageComponent();

		void Update() override;
		void FixedUpdate() override;
		void ReceiveMessage(const MessageWrapper* pMessage) override;
		void Render() const override;

	private:
		std::shared_ptr<Texture2D> m_Texture;
		std::string m_SourcePath;
	};
}