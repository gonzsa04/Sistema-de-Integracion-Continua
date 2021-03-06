#pragma once
#include "checkML.h"
#include "ClickeableGO.h"


class ItemInventario :
	public ClickeableGO
{
public:
	ItemInventario() {}
	ItemInventario(SDLApp* game, int x, int y, int w, int h, string _desc, string _tag, Texture* texture, bool permanente = false);
	virtual ~ItemInventario();
	virtual void act(MainCharacter* player = nullptr);
	string getTag() { return tag; };
	string getDescription() { return desc; }
	virtual void saveToJson(json& j) { if (this->isActive()) { json aux;  Entity::saveToJson(aux); aux["tag"] = getTag(); aux["descripcion"] = getDescription();  j["ItemInventario"].push_back(aux); } }
	bool const isPermanent() { return permanente_; };

	void use(MainCharacter* player);
	inline void setTag(std::string value) { tag = value; }

private:
	string desc;
	string tag;
	bool permanente_;
};

