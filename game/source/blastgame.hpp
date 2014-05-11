#ifndef BLASTGAME_HPP
#define BLASTGAME_HPP

#include <featherkit/structure.hpp>

#include <featherkit/userinterface.hpp>

#include <featherkit/ui/sdl2windowbackend.hpp>
#include <featherkit/ui/sdl2inputbackend.hpp>

#include <featherkit/render2d.hpp>

#include "badguy.hpp"
#include "swordfish.hpp"

struct ProjectileInfo
{
	glm::vec2 position;
	glm::vec2 velocity;
	fea::Color color;
	Ship* owner;
	float distanceToDeath;

	ProjectileInfo(const glm::vec2& start,
				   const glm::vec2& velocity,
				   const fea::Color& c,
				   Ship* owner)
		: position(start), velocity(velocity), color(c), owner(owner),
		  distanceToDeath(10000.f) {}
};

class BlastGame : public fea::Application
{
public:
	BlastGame();
protected:
	void setup(const std::vector<std::string> &args) override;
	void loop() override;
	void destroy() override;
private:

	fea::Window window;
	fea::InputHandler input;

	fea::Renderer2D renderer;

	std::vector<float> gaussian_values;
	fea::Shader framebufferShader;
	fea::Shader brightnessShader;
	fea::Quad framebufferQuad;

	fea::Quad quad;
	fea::Quad projectile;
	fea::Texture beam;
	fea::Texture circle;

	BadGuy bg;
	Swordfish sf;

	std::vector<Ship*> ships;

	std::vector<ProjectileInfo> projectiles;

	void drawBeamY(const float X);
	void drawBeamX(const float Y);

	void drawProjectile(const ProjectileInfo& pi);
};

#endif // BLASTGAME_HPP
