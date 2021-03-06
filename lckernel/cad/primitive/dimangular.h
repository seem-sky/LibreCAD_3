#pragma once

#include "cad/const.h"
#include "cad/interface/entityvisitor.h"
#include "cad/interface/entitydispatch.h"

#include "cad/primitive/dimension.h"
#include "cad/base/cadentity.h"
#include "cad/vo/entitycoordinate.h"
#include "cad/math/lcmath.h"
#include <cad/primitive/point.h>

namespace lc {
    class DimAngular;
    typedef std::shared_ptr<DimAngular> DimAngular_SPtr;
    typedef std::shared_ptr<const DimAngular> DimAngular_CSPtr;


    class DimAngular : public std::enable_shared_from_this<DimAngular>, public CADEntity, public Dimension {
        public:


            /**
            * @brief
            * @param Dimension dimension
            * @param geo::Coordinate extension_point1
            * @param geo::Coordinate extension_point2
            * @param double oblique
            * @param Layer_CSPtr layer
            */
            DimAngular(geo::Coordinate const& definitionPoint, geo::Coordinate const& middleOfText, TextConst::AttachmentPoint const& attachmentPoint, double textAngle, double const lineSpacingFactor,
                       TextConst::LineSpacingStyle const& lineSpacingStyle, std::string const& explicitValue,
                       geo::Coordinate const& _defLine11, geo::Coordinate const& _defLine12, geo::Coordinate const& _defLine21, geo::Coordinate const& _defLine22, const Layer_CSPtr layer, const MetaInfo_CSPtr metaInfo);


            DimAngular(const DimAngular_CSPtr other, bool sameID = false);

            static DimAngular_SPtr dimAuto(geo::Coordinate const& p1, geo::Coordinate const& p2, double const textOffset, std::string const& explicitValue, const Layer_CSPtr layer, const MetaInfo_CSPtr metaInfo);

        public:
            /**
            * @brief move, moves by an offset
            * @param geo::Coordinate offset
            * @return CADEntity_CSPtr moved entity
            */
            virtual CADEntity_CSPtr move(const geo::Coordinate& offset) const;

            /**
            * @brief copy, copies by an offset
            * @param geo::Coordinate offset
            * @return CADEntity_CSPtr copied entity
            */
            virtual CADEntity_CSPtr copy(const geo::Coordinate& offset) const;

            /**
            * @brief rotate, rotate operation
            * @param geo::Coordinate rotation_center
            * @param double rotation_angle
            * @return CADEntity_CSPtr rotated entity
            */
            virtual CADEntity_CSPtr rotate(const geo::Coordinate& rotation_center, const double rotation_angle) const;

            /**
            * @brief scale, scales the entity
            * @param geo::Coordinate scale_center
            * @param double scale_factor
            * @return
            */
            virtual CADEntity_CSPtr scale(const geo::Coordinate& scale_center, const geo::Coordinate& scale_factor) const;

            /**
            * @brief boundingBox of the entity
            * @return geo::Area area
            */
            virtual const geo::Area boundingBox() const;

            virtual CADEntity_CSPtr modify(Layer_CSPtr layer, const MetaInfo_CSPtr metaInfo) const;

            geo::Coordinate defLine11() const;
            geo::Coordinate defLine12() const;
            geo::Coordinate defLine21() const;
            geo::Coordinate defLine22() const;
        protected:
            const geo::Coordinate _defLine11;
            const geo::Coordinate _defLine12;
            const geo::Coordinate _defLine21;
            const geo::Coordinate _defLine22;
        public:
            virtual void accept(const geo::Vector& o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(Point_CSPtr o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(Line_CSPtr o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(Circle_CSPtr o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(Arc_CSPtr o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(Ellipse_CSPtr o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(Text_CSPtr o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(Spline_CSPtr o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(MText_CSPtr o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(DimLinear_CSPtr o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(DimAligned_CSPtr o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(DimDiametric_CSPtr o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(DimAngular_CSPtr o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(DimRadial_CSPtr o, EntityVisitor& ei) const {
                ei.visit(shared_from_this(), o);
            }
            virtual void accept(CADEntity_CSPtr o, EntityVisitor& ei) const {
                o->accept(shared_from_this(), ei);
            }
            virtual void dispatch(EntityDispatch& ed) const {
                ed.visit(shared_from_this());
            }
    };
}

// DIMLINEAR_H
