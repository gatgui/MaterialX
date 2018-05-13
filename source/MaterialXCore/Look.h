//
// TM & (c) 2017 Lucasfilm Entertainment Company Ltd. and Lucasfilm Ltd.
// All rights reserved.  See LICENSE.txt for license.
//

#ifndef MATERIALX_LOOK_H
#define MATERIALX_LOOK_H

/// @file
/// Look element subclasses

#include <MaterialXCore/Library.h>

#include <MaterialXCore/Material.h>
#include <MaterialXCore/Property.h>

namespace MaterialX
{

/// A shared pointer to a Look
using LookPtr = shared_ptr<class Look>;
/// A shared pointer to a const Look
using ConstLookPtr = shared_ptr<const class Look>;

/// A shared pointer to a LookInherit
using LookInheritPtr = shared_ptr<class LookInherit>;
/// A shared pointer to a const LookInherit
using ConstLookInheritPtr = shared_ptr<const class LookInherit>;

/// A shared pointer to a MaterialAssign
using MaterialAssignPtr = shared_ptr<class MaterialAssign>;
/// A shared pointer to a const MaterialAssign
using ConstMaterialAssignPtr = shared_ptr<const class MaterialAssign>;

/// A shared pointer to a Visibility
using VisibilityPtr = shared_ptr<class Visibility>;
/// A shared pointer to a const Visibility
using ConstVisibilityPtr = shared_ptr<const class Visibility>;

/// @class Look
/// A look element within a Document.
class Look : public Element
{
  public:
    Look(ElementPtr parent, const string& name) :
        Element(parent, CATEGORY, name)
    {
    }
    virtual ~Look() { }

    /// @}
    /// @name MaterialAssign Elements
    /// @{

    /// Add a MaterialAssign to the look.
    /// @param name The name of the new MaterialAssign.
    ///     If no name is specified, then a unique name will automatically be
    ///     generated.
    /// @param material An optional material string, which should match the
    ///     name of the Material element to be assigned.
    /// @return A shared pointer to the new MaterialAssign.
    MaterialAssignPtr addMaterialAssign(const string& name = EMPTY_STRING,
                                        const string& material = EMPTY_STRING);

    /// Return the MaterialAssign, if any, with the given name.
    MaterialAssignPtr getMaterialAssign(const string& name) const
    {
        return getChildOfType<MaterialAssign>(name);
    }

    /// Return a vector of all MaterialAssign elements in the look.
    vector<MaterialAssignPtr> getMaterialAssigns() const
    {
        return getChildrenOfType<MaterialAssign>();
    }

    /// Return a vector of all MaterialAssign elements that belong to this look,
    /// taking look inheritance into account.
    vector<MaterialAssignPtr> getActiveMaterialAssigns() const;

    /// Remove the MaterialAssign, if any, with the given name.
    void removeMaterialAssign(const string& name)
    {
        removeChildOfType<MaterialAssign>(name);
    }

    /// @}
    /// @name PropertyAssign Elements
    /// @{

    /// Add a PropertyAssign to the look.
    /// @param name The name of the new PropertyAssign.
    ///     If no name is specified, then a unique name will automatically be
    ///     generated.
    /// @return A shared pointer to the new PropertyAssign.
    PropertyAssignPtr addPropertyAssign(const string& name = EMPTY_STRING)
    {
        return addChild<PropertyAssign>(name);
    }

    /// Return the PropertyAssign, if any, with the given name.
    PropertyAssignPtr getPropertyAssign(const string& name) const
    {
        return getChildOfType<PropertyAssign>(name);
    }

    /// Return a vector of all PropertyAssign elements in the look.
    vector<PropertyAssignPtr> getPropertyAssigns() const
    {
        return getChildrenOfType<PropertyAssign>();
    }

    /// Return a vector of all PropertyAssign elements that belong to this look,
    /// taking look inheritance into account.
    vector<PropertyAssignPtr> getActivePropertyAssigns() const;

    /// Remove the PropertyAssign, if any, with the given name.
    void removePropertyAssign(const string& name)
    {
        removeChildOfType<PropertyAssign>(name);
    }

    /// @}
    /// @name PropertySetAssign Elements
    /// @{

    /// Add a PropertySetAssign to the look.
    /// @param name The name of the new PropertySetAssign.
    ///     If no name is specified, then a unique name will automatically be
    ///     generated.
    /// @return A shared pointer to the new PropertySetAssign.
    PropertySetAssignPtr addPropertySetAssign(const string& name = EMPTY_STRING)
    {
        return addChild<PropertySetAssign>(name);
    }

    /// Return the PropertySetAssign, if any, with the given name.
    PropertySetAssignPtr getPropertySetAssign(const string& name) const
    {
        return getChildOfType<PropertySetAssign>(name);
    }

    /// Return a vector of all PropertySetAssign elements in the look.
    vector<PropertySetAssignPtr> getPropertySetAssigns() const
    {
        return getChildrenOfType<PropertySetAssign>();
    }

    /// Return a vector of all PropertySetAssign elements that belong to this look,
    /// taking look inheritance into account.
    vector<PropertySetAssignPtr> getActivePropertySetAssigns() const;

    /// Remove the PropertySetAssign, if any, with the given name.
    void removePropertySetAssign(const string& name)
    {
        removeChildOfType<PropertySetAssign>(name);
    }

    /// @}
    /// @name Visibility Elements
    /// @{

    /// Add a Visibility to the look.
    /// @param name The name of the new Visibility.
    ///     If no name is specified, then a unique name will automatically be
    ///     generated.
    /// @return A shared pointer to the new Visibility.
    VisibilityPtr addVisibility(const string& name = EMPTY_STRING)
    {
        return addChild<Visibility>(name);
    }

    /// Return the Visibility, if any, with the given name.
    VisibilityPtr getVisibility(const string& name) const
    {
        return getChildOfType<Visibility>(name);
    }

    /// Return a vector of all Visibility elements in the look.
    vector<VisibilityPtr> getVisibilities() const
    {
        return getChildrenOfType<Visibility>();
    }

    /// Return a vector of all Visibility elements that belong to this look,
    /// taking look inheritance into account.
    vector<VisibilityPtr> getActiveVisibilities() const;

    /// Remove the Visibility, if any, with the given name.
    void removeVisibility(const string& name)
    {
        removeChildOfType<Visibility>(name);
    }

    /// @}
    /// @name LookInherit Elements
    /// @{

    /// Add a LookInherit to the look.
    /// @param name The name of the new LookInherit.
    ///     If no name is specified, then a unique name will automatically be
    ///     generated.
    /// @return A shared pointer to the new LookInherit.
    LookInheritPtr addLookInherit(const string& name = EMPTY_STRING)
    {
        return addChild<LookInherit>(name);
    }

    /// Return the LookInherit, if any, with the given name.
    LookInheritPtr getLookInherit(const string& name) const
    {
        return getChildOfType<LookInherit>(name);
    }

    /// Return a vector of all LookInherit elements in the look.
    vector<LookInheritPtr> getLookInherits() const
    {
        return getChildrenOfType<LookInherit>();
    }

    /// Remove the LookInherit, if any, with the given name.
    void removeLookInherit(const string& name)
    {
        removeChildOfType<LookInherit>(name);
    }

    /// @}
    /// @name Inheritance
    /// @{

    /// Set the look element that this one inherits from.
    void setInheritsFrom(ElementPtr look) override;

    /// Return the look element, if any, that this one inherits from.
    ElementPtr getInheritsFrom() const override;

    /// @}

  public:
    static const string CATEGORY;
};

/// @class LookInherit
/// A look inheritance element within a Look.
class LookInherit : public Element
{
public:
    LookInherit(ElementPtr parent, const string& name) :
        Element(parent, CATEGORY, name)
    {
    }
    virtual ~LookInherit() { }

public:
    static const string CATEGORY;
};

/// @class MaterialAssign
/// A material assignment element within a Look.
class MaterialAssign : public GeomElement
{
  public:
    MaterialAssign(ElementPtr parent, const string& name) :
        GeomElement(parent, CATEGORY, name)
    {
    }
    virtual ~MaterialAssign() { }

    /// @name Material String
    /// @{

    /// Set the material string for the MaterialAssign.
    void setMaterial(const string& material)
    {
        setAttribute(MATERIAL_ATTRIBUTE, material);
    }

    /// Return true if the given MaterialAssign has a material string.
    bool hasMaterial() const
    {
        return hasAttribute(MATERIAL_ATTRIBUTE);
    }

    /// Return the material string for the MaterialAssign.
    const string& getMaterial() const
    {
        return getAttribute(MATERIAL_ATTRIBUTE);
    }

    /// @}
    /// @name Exclusive
    /// @{

    /// Set the exclusive boolean for the MaterialAssign.
    void setExclusive(bool value)
    {
        setTypedAttribute<bool>(EXCLUSIVE_ATTRIBUTE, value);
    }

    /// Return the exclusive boolean for the MaterialAssign.
    bool getExclusive() const
    {
        return getTypedAttribute<bool>(EXCLUSIVE_ATTRIBUTE);
    }

    /// @}
    /// @name Material References
    /// @{

    /// Return the Material, if any, referenced by the MaterialAssign.
    MaterialPtr getReferencedMaterial() const;

    /// @}

  public:
    static const string CATEGORY;
    static const string MATERIAL_ATTRIBUTE;
    static const string EXCLUSIVE_ATTRIBUTE;
};

/// @class Visibility
/// A visibility element within a Look.
///
/// A Visibility describes the visibility relationship between two geometries
/// or geometric collections.
///
/// @todo Add a Look::geomIsVisible method that computes the visibility between
///     two geometries in the context of a specific Look.
class Visibility : public GeomElement
{
  public:
    Visibility(ElementPtr parent, const string& name) :
        GeomElement(parent, CATEGORY, name)
    {
    }
    virtual ~Visibility() { }

    /// @name Viewer Geom
    /// @{

    /// Set the viewer geom string of the element.
    void setViewerGeom(const string& geom)
    {
        setAttribute(VIEWER_GEOM_ATTRIBUTE, geom);
    }

    /// Return true if the given element has a viewer geom string.
    bool hasViewerGeom() const
    {
        return hasAttribute(VIEWER_GEOM_ATTRIBUTE);
    }

    /// Return the viewer geom string of the element.
    const string& getViewerGeom() const
    {
        return getAttribute(VIEWER_GEOM_ATTRIBUTE);
    }

    /// @}
    /// @name Viewer Collection
    /// @{

    /// Set the viewer geom string of the element.
    void setViewerCollection(const string& collection)
    {
        setAttribute(VIEWER_COLLECTION_ATTRIBUTE, collection);
    }

    /// Return true if the given element has a viewer collection string.
    bool hasViewerCollection() const
    {
        return hasAttribute(VIEWER_COLLECTION_ATTRIBUTE);
    }

    /// Return the viewer collection string of the element.
    const string& getViewerCollection() const
    {
        return getAttribute(VIEWER_COLLECTION_ATTRIBUTE);
    }

    /// @}
    /// @name Visibility Type
    /// @{

    /// Set the visibility type string of the element.
    void setVisibilityType(const string& type)
    {
        setAttribute(VISIBILITY_TYPE_ATTRIBUTE, type);
    }

    /// Return true if the given element has a visibility type string.
    bool hasVisibilityType() const
    {
        return hasAttribute(VISIBILITY_TYPE_ATTRIBUTE);
    }

    /// Return the visibility type string of the element.
    const string& getVisibilityType() const
    {
        return getAttribute(VISIBILITY_TYPE_ATTRIBUTE);
    }

    /// @}
    /// @name Visible
    /// @{

    /// Set the visible boolean of the element.
    void setVisible(bool visible)
    {
        setTypedAttribute<bool>(VISIBLE_ATTRIBUTE, visible);
    }

    /// Return the visible boolean of the element.
    bool getVisible() const
    {
        return getTypedAttribute<bool>(VISIBLE_ATTRIBUTE);
    }

    /// @}

public:
    static const string CATEGORY;
    static const string VIEWER_GEOM_ATTRIBUTE;
    static const string VIEWER_COLLECTION_ATTRIBUTE;
    static const string VISIBILITY_TYPE_ATTRIBUTE;
    static const string VISIBLE_ATTRIBUTE;
};

} // namespace MaterialX

#endif
