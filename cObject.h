#pragma once
class cCollider;
class cObject
{
public:
	inline static long idGenerator = 0;

	CMeshLoader* mesh;
	cObject* parent;

	Vec3 pos = Vec3(0, 0, 0);
	Vec3 size = Vec3(1, 1, 1);
	Vec3 rot = Vec3(0, 0, 0);
	Vec3 hitDir = Vec3(0, 0, 0);

	Mat matWorld;

	Quat resultQ = Quat(0, 0, 0, 1);
	cCollider* collider = nullptr;

	bool isDestroy = false;
	bool isDead = false;

	bool isUseQua = false;
	bool isUseQuaAllRot = false;

	float hp = 0;
	float damage = 0;
	float Gravity = 300;

	bool isHit = false;
	bool isBlend = false;
	bool isImotal = false;
	bool isDash = false;
	bool isJump = false;
	bool isBottom = true;

	bool isHitting = false;

	Color curColor = Color(1, 1, 1, 1);
	Color oldColor = Color(1, 1, 1, 1);

	Tag tag;

	system_clock::time_point dieTime;
	system_clock::time_point blendTime;
	system_clock::time_point hitTime;

public:
	cObject();
	virtual ~cObject();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

	virtual void ObjectDead() = 0;
	virtual void OnCollision(cCollider* col) = 0;


	virtual void DestroyCollider();
	virtual void TransformUpdate();
	virtual void ColliderSet(float _radius, cObject* _parent);
};

