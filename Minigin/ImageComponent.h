#pragma once
#include "RenderComponent.h"
#include <string>
#include <memory>

namespace dae
{
	class Texture2D;

	class ImageComponent :
		public RenderComponent
	{
	public:
		ImageComponent(std::string sourcePath);
		virtual ~ImageComponent();

		void Update() override;
		void FixedUpdate() override;
		void ReceiveMessage(const MessageWrapper* pMessage) override;
		void Render() const override;
	private:
		std::shared_ptr<Texture2D> m_Texture;
	};
}