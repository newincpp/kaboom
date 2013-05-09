#include "Model.hh"

GDLModel::GDLModel(const std::string& fileName) {
    _model = gdl::Model::load(fileName);
}

void GDLModel::initialize(void) {
}

GDLModel::~GDLModel(void) {
}

void GDLModel::setAnim(const std::string& newAnim) {
    _curentAnim = newAnim;
}

void GDLModel::update(/*gdl::GameClock const & gameClock, */gdl::Input & input) {
    //_model.update(gameClock);
    if (input.isKeyDown(gdl::Keys::P) == true)
	_model.play("Take 001");
}

void GDLModel::draw(void) {
    _model.draw();
}
