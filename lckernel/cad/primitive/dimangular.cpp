#include "cad/primitive/dimangular.h"


using namespace lc;

DimAngular::DimAngular(
    geo::Coordinate const& definitionPoint,
    geo::Coordinate const& middleOfText,
    TextConst::AttachmentPoint const& attachmentPoint,
    double textAngle,
    double const lineSpacingFactor,
    TextConst::LineSpacingStyle const& lineSpacingStyle,
    std::string const& explicitValue,
    geo::Coordinate const& defLine11,
    geo::Coordinate const& defLine12,
    geo::Coordinate const& defLine21,
    geo::Coordinate const& defLine22,
    const Layer_CSPtr layer,
    const MetaInfo_CSPtr metaInfo) :
    CADEntity(layer, metaInfo),
    Dimension(definitionPoint, middleOfText, attachmentPoint, textAngle, lineSpacingFactor, lineSpacingStyle, explicitValue),
    _defLine11(defLine11),
    _defLine12(defLine12),
    _defLine21(defLine21),
    _defLine22(defLine22) {

}


DimAngular::DimAngular(const DimAngular_CSPtr other, bool sameID) :
    CADEntity(other, sameID),
    Dimension(*other),
    _defLine11(other->_defLine11),
    _defLine12(other->_defLine12),
    _defLine21(other->_defLine21),
    _defLine22(other->_defLine22) {
}

DimAngular_SPtr DimAngular::dimAuto(geo::Coordinate const& p2, geo::Coordinate const& p3, double const textOffset, std::string const& explicitValue, const Layer_CSPtr layer, const MetaInfo_CSPtr metaInfo) {

    geo::Coordinate dir = (p3 - p2).rotate(0.5 * M_PI);
    geo::Coordinate p0 = p3.move(dir, textOffset);
    geo::Coordinate middletext(p2.mid(p3).move(dir, textOffset));


    return std::make_shared<DimAngular>(p0, middletext, TextConst::AttachmentPoint::Top_center, 0., 0., TextConst::LineSpacingStyle::AtLeast, explicitValue, p2, p3, p3, p3, layer, metaInfo);
}


CADEntity_CSPtr DimAngular::move(const geo::Coordinate& offset) const {
    auto newDimAngular = std::make_shared<DimAngular>(this->definitionPoint() + offset, this->middleOfText() + offset, this->attachmentPoint(), this->textAngle(), this->lineSpacingFactor(), this->lineSpacingStyle(), this->explicitValue(), this->_defLine11 + offset, this->_defLine12 + offset, this->_defLine21 + offset, this->_defLine22 + offset, this->layer(), this->metaInfo());
    newDimAngular->setID(this->id());
    return newDimAngular;
}

CADEntity_CSPtr DimAngular::copy(const geo::Coordinate& offset) const {
    auto newDimAngular = std::make_shared<DimAngular>(this->definitionPoint() + offset, this->middleOfText() + offset, this->attachmentPoint(), this->textAngle(), this->lineSpacingFactor(), this->lineSpacingStyle(), this->explicitValue(), this->_defLine11 + offset, this->_defLine12 + offset, this->_defLine21 + offset, this->_defLine22 + offset, this->layer(), this->metaInfo());
    return newDimAngular;
}

CADEntity_CSPtr DimAngular::rotate(const geo::Coordinate& rotation_center, const double rotation_angle) const {
    auto newDimAngular = std::make_shared<DimAngular>(this->definitionPoint().rotate(rotation_center, rotation_angle),
                                                      this->middleOfText().rotate(rotation_center, rotation_angle), this->attachmentPoint(), this->textAngle(), this->lineSpacingFactor(), this->lineSpacingStyle(), this->explicitValue(), this->_defLine11.rotate(rotation_center, rotation_angle), this->_defLine12.rotate(rotation_center, rotation_angle), this->_defLine21.rotate(rotation_center, rotation_angle), this->_defLine22.rotate(rotation_center, rotation_angle), this->layer(), this->metaInfo());
    return newDimAngular;
}

CADEntity_CSPtr DimAngular::scale(const geo::Coordinate& scale_center, const geo::Coordinate& scale_factor) const {
    auto newDimAngular = std::make_shared<DimAngular>(this->definitionPoint().scale(scale_center, scale_factor),
                                                      this->middleOfText().scale(scale_center, scale_factor), this->attachmentPoint(), this->textAngle(), this->lineSpacingFactor(), this->lineSpacingStyle(), this->explicitValue(), this->_defLine11.scale(scale_center, scale_factor), this->_defLine12.scale(scale_center, scale_factor), this->_defLine21.scale(scale_center, scale_factor), this->_defLine22.scale(scale_center, scale_factor), this->layer(), this->metaInfo());
    return newDimAngular;
}

const geo::Area DimAngular::boundingBox() const {
    // TODO create proper bounding box for DimAngular
    return geo::Area(this->middleOfText(), 0., 0.);
}

CADEntity_CSPtr DimAngular::modify(Layer_CSPtr layer, const MetaInfo_CSPtr metaInfo) const {
    auto newDimAngular = std::make_shared<DimAngular>(
                             this->definitionPoint(), this->middleOfText(), this->attachmentPoint(), this->textAngle(), this->lineSpacingFactor(), this->lineSpacingStyle(), this->explicitValue(), this->_defLine11, this->_defLine12, this->_defLine21, this->_defLine22, this->layer(), metaInfo);
    return newDimAngular;
}

geo::Coordinate DimAngular::defLine11() const {
    return _defLine11;
}

geo::Coordinate DimAngular::defLine12() const {
    return _defLine12;
}

geo::Coordinate DimAngular::defLine21() const {
    return _defLine21;
}

geo::Coordinate DimAngular::defLine22() const {
    return _defLine22;
}
