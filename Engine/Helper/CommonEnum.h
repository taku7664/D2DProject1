#pragma once

enum class GameState
{
	Create,
	Active,
	Passive,
	Destroy,
};

enum class WorldTag
{
	Default,
	Load,
	Title,
	Play,
	SIZE,
};

enum class LayerTag
{
	Defalut,
	BackGround,
	Map,
	Tile,
	Wall,
	Object,
	Particle,
	UI,
	SIZE,
};

enum class ObjectTag
{
	Defalut,
	Camera,
	Player,
	Monster,
	BodyBox,
	HitBox,
	Particle,
	UI,
	SIZE,
};

enum class ObjectType
{
	None,
	Actor,
	DynamicText,
	InputText,
	SIZE
};

enum class ComponentType
{
	BoxCollider2D,
	CircleCollider2D,
	SpriteRenderer2D,
	RectRenderer,
	Animator2D,
	Button,
	Script,
	FiniteStateMachine,
	Transform2D,
	Camera,
	SIZE,
};

enum class ResourceType
{
	NONE,
	Texture2D,
	Sprite2D,
	Animation2D,
	SIZE,
};

enum KeyType // 키보드
{
	UP = VK_UP,
	DOWN = VK_DOWN,
	LEFT = VK_LEFT,
	RIGHT = VK_RIGHT,
	SPACEBAR = VK_SPACE,
};

enum class MouseType // 마우스
{
	LEFT = VK_LBUTTON,
	ROLL = VK_MBUTTON,
	RIGHT = VK_RBUTTON,
};