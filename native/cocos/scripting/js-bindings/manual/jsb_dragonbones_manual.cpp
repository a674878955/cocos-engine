#include "jsb_dragonbones_manual.hpp"
#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"
#include "cocos/scripting/js-bindings/manual/jsb_conversions.hpp"
#include "cocos/scripting/js-bindings/manual/jsb_global.h"
#include "cocos/scripting/js-bindings/auto/jsb_cocos2dx_dragonbones_auto.hpp"
#include "cocos/editor-support/dragonbones/cocos2dx/CCDragonBonesHeaders.h"

#include "cocos2d.h"

using namespace cocos2d;


static bool js_cocos2dx_dragonbones_Armature_getAnimation(se::State& s)
{
    if (s.args().size() == 0)
    {
        dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
        dragonBones::Animation& ret = cobj->getAnimation();
        bool ok = native_ptr_to_seval<dragonBones::Animation>(&ret, __jsb_dragonBones_Animation_class, &s.rval());
        JSB_PRECONDITION2(ok, false, "Convert dragonBones::Animation to se::Value failed!");
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)s.args().size(), 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getAnimation)

static bool js_cocos2dx_dragonbones_Armature_getArmatureData(se::State& s)
{
    if (s.args().size() == 0)
    {
        dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
        const dragonBones::ArmatureData& ret = cobj->getArmatureData();
        bool ok = native_ptr_to_seval<dragonBones::ArmatureData>((dragonBones::ArmatureData*)&ret, __jsb_dragonBones_ArmatureData_class, &s.rval());
        JSB_PRECONDITION2(ok, false, "Convert dragonBones::ArmatureData to se::Value failed!");
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)s.args().size(), 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getArmatureData)

static bool js_cocos2dx_dragonbones_Armature_getDisplay(se::State& s)
{
    if (s.args().size() == 0)
    {
        dragonBones::Armature* cobj = (dragonBones::Armature*)s.nativeThisObject();
        dragonBones::CCArmatureDisplay* ret = dynamic_cast<dragonBones::CCArmatureDisplay*>(cobj->getDisplay());
        if (ret != nullptr)
        {
            bool ok = native_ptr_to_seval<dragonBones::CCArmatureDisplay>(ret, __jsb_dragonBones_CCArmatureDisplay_class, &s.rval());
            JSB_PRECONDITION2(ok, false, "Convert dragonBones::Animation to se::Value failed!");
        }
        else
        {
            s.rval().setNull();
        }
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)s.args().size(), 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Armature_getDisplay)

static bool js_cocos2dx_dragonbones_CCArmatureDisplay_getAnimation(se::State& s)
{
    if (s.args().size() == 0)
    {
        dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay*)s.nativeThisObject();
        dragonBones::Animation& ret = cobj->getAnimation();
        bool ok = native_ptr_to_seval<dragonBones::Animation>(&ret, __jsb_dragonBones_Animation_class, &s.rval());
        JSB_PRECONDITION2(ok, false, "Convert dragonBones::Animation to se::Value failed!");
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)s.args().size(), 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCArmatureDisplay_getAnimation)

static bool js_cocos2dx_dragonbones_AnimationState_getAnimationData(se::State& s)
{
    if (s.args().size() == 0)
    {
        dragonBones::AnimationState* cobj = (dragonBones::AnimationState*)s.nativeThisObject();
        const dragonBones::AnimationData& ret = cobj->getAnimationData();
        bool ok = native_ptr_to_seval<dragonBones::AnimationData>((dragonBones::AnimationData*)&ret, __jsb_dragonBones_AnimationData_class, &s.rval());
        JSB_PRECONDITION2(ok, false, "Convert dragonBones::AnimationData to se::Value failed!");
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)s.args().size(), 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_AnimationState_getAnimationData)

static bool js_cocos2dx_dragonbones_ArmatureData_get_animations(se::State& s)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    se::Object* retObj = se::Object::createPlainObject(true);
    bool ok = false;
    se::Value tmp;
    for (const auto& e : cobj->animations)
    {
        if (!e.first.empty())
        {
            ok = native_ptr_to_seval<dragonBones::AnimationData>(e.second, __jsb_dragonBones_AnimationData_class, &tmp);
            JSB_PRECONDITION2(ok, false, "Convert dragonBones::AnimationData to se::Value failed!");
            retObj->setProperty(e.first.c_str(), tmp);
        }
    }
    retObj->switchToUnrooted();
    s.rval().setObject(retObj);
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_ArmatureData_get_animations)

static bool js_cocos2dx_dragonbones_ArmatureData_get_bones(se::State& s)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    se::Object* retObj = se::Object::createPlainObject(true);
    bool ok = false;
    se::Value tmp;
    for (const auto& e : cobj->bones)
    {
        if (!e.first.empty())
        {
            ok = native_ptr_to_seval<dragonBones::BoneData>(e.second, __jsb_dragonBones_BoneData_class, &tmp);
            JSB_PRECONDITION2(ok, false, "Convert dragonBones::AnimationData to se::Value failed!");
            retObj->setProperty(e.first.c_str(), tmp);
        }
    }
    retObj->switchToUnrooted();
    s.rval().setObject(retObj);
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_ArmatureData_get_bones)

static bool js_cocos2dx_dragonbones_ArmatureData_get_skins(se::State& s)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    se::Object* retObj = se::Object::createPlainObject(true);
    bool ok = false;
    se::Value tmp;
    for (const auto& e : cobj->skins)
    {
        if (!e.first.empty())
        {
            ok = native_ptr_to_seval<dragonBones::SkinData>(e.second, __jsb_dragonBones_SkinData_class, &tmp);
            JSB_PRECONDITION2(ok, false, "Convert dragonBones::AnimationData to se::Value failed!");
            retObj->setProperty(e.first.c_str(), tmp);
        }
    }
    retObj->switchToUnrooted();
    s.rval().setObject(retObj);
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_ArmatureData_get_skins)

static bool js_cocos2dx_dragonbones_ArmatureData_get_slots(se::State& s)
{
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData*)s.nativeThisObject();
    se::Object* retObj = se::Object::createPlainObject(true);
    bool ok = false;
    se::Value tmp;
    for (const auto& e : cobj->slots)
    {
        if (!e.first.empty())
        {
            ok = native_ptr_to_seval<dragonBones::SlotData>(e.second, __jsb_dragonBones_SlotData_class, &tmp);
            JSB_PRECONDITION2(ok, false, "Convert dragonBones::AnimationData to se::Value failed!");
            retObj->setProperty(e.first.c_str(), tmp);
        }
    }
    retObj->switchToUnrooted();
    s.rval().setObject(retObj);
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_ArmatureData_get_slots)

static bool js_cocos2dx_dragonbones_DragonBonesData_get_armatureNames(se::State& s)
{
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData*)s.nativeThisObject();

    const auto& ret = cobj->getArmatureNames();
    bool ok = std_vector_string_to_seval(ret, &s.rval());
    JSB_PRECONDITION2(ok, false, "Convert ArmatureNames to se::Value failed!");
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_DragonBonesData_get_armatureNames)

static bool js_cocos2dx_dragonbones_WorldClock_getClock(se::State& s)
{
    bool ok = native_ptr_to_seval<dragonBones::WorldClock>(&dragonBones::WorldClock::clock, __jsb_dragonBones_WorldClock_class, &s.rval());
    JSB_PRECONDITION2(ok, false, "Convert WorldClock::clock to se::Value failed!");
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_WorldClock_getClock)

static bool js_cocos2dx_dragonbones_WorldClock_add(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();

    if (argc == 1)
    {
        dragonBones::WorldClock* cobj = (dragonBones::WorldClock *)s.nativeThisObject();
        const se::Value& arg0Val = args[0];
        if (!arg0Val.isNull())
        {
            dragonBones::IAnimateble* arg0 = nullptr;
            bool ok = arg0Val.isObject();
            JSB_PRECONDITION2(ok, false, "WorldClock_add argument isn't object");

            void* animateable = nullptr;
            ok = seval_to_native_ptr(arg0Val, &animateable);
            JSB_PRECONDITION2(ok, false, "WorldClock_add argument get native ptr failed!");

            auto armatureObj = static_cast<dragonBones::Armature*>(animateable);
            auto clockObj = static_cast<dragonBones::WorldClock*>(animateable);
            if (armatureObj) {
                arg0 = dynamic_cast<dragonBones::IAnimateble*>(armatureObj);
            }
            else {
                arg0 = dynamic_cast<dragonBones::IAnimateble*>(clockObj);
            }

            cobj->add(arg0);
        }

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_WorldClock_add)

static bool js_cocos2dx_dragonbones_WorldClock_remove(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();

    if (argc == 1)
    {
        dragonBones::WorldClock* cobj = (dragonBones::WorldClock *)s.nativeThisObject();
        const se::Value& arg0Val = args[0];
        if (!arg0Val.isNull())
        {
            dragonBones::IAnimateble* arg0 = nullptr;
            bool ok = arg0Val.isObject();
            JSB_PRECONDITION2(ok, false, "WorldClock_remove argument isn't object");

            void* animateable = nullptr;
            ok = seval_to_native_ptr(arg0Val, &animateable);
            JSB_PRECONDITION2(ok, false, "WorldClock_remove argument get native ptr failed!");

            auto armatureObj = static_cast<dragonBones::Armature*>(animateable);
            auto clockObj = static_cast<dragonBones::WorldClock*>(animateable);
            if (armatureObj) {
                arg0 = dynamic_cast<dragonBones::IAnimateble*>(armatureObj);
            }
            else {
                arg0 = dynamic_cast<dragonBones::IAnimateble*>(clockObj);
            }

            cobj->remove(arg0);
        }

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_WorldClock_remove)

static bool js_cocos2dx_dragonbones_CCFactory_getFactory(se::State& s)
{
    if (s.args().size() == 0)
    {
        const dragonBones::CCFactory& ret = dragonBones::CCFactory::factory;
        bool ok = native_ptr_to_seval<dragonBones::CCFactory>((dragonBones::CCFactory*)&ret, __jsb_dragonBones_CCFactory_class, &s.rval());
        JSB_PRECONDITION2(ok, false, "Convert dragonBones::CCFactory to se::Value failed!");
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)s.args().size(), 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_CCFactory_getFactory)

static bool js_cocos2dx_dragonbones_TransformObject_getGlobal(se::State& s)
{
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject *)s.nativeThisObject();
    bool ok = native_ptr_to_seval<dragonBones::Transform>(&cobj->global, __jsb_dragonBones_Transform_class, &s.rval());
    JSB_PRECONDITION2(ok, false, "Convert dragonBones::Transform to se::Value failed!");
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_TransformObject_getGlobal)

static bool js_cocos2dx_dragonbones_TransformObject_getOrigin(se::State& s)
{
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject *)s.nativeThisObject();
    bool ok = native_ptr_to_seval<dragonBones::Transform>(&cobj->origin, __jsb_dragonBones_Transform_class, &s.rval());
    JSB_PRECONDITION2(ok, false, "Convert dragonBones::Transform to se::Value failed!");
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_TransformObject_getOrigin)

static bool js_cocos2dx_dragonbones_TransformObject_getOffset(se::State& s)
{
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject *)s.nativeThisObject();
    bool ok = native_ptr_to_seval<dragonBones::Transform>(&cobj->offset, __jsb_dragonBones_Transform_class, &s.rval());
    JSB_PRECONDITION2(ok, false, "Convert dragonBones::Transform to se::Value failed!");
    return true;
}
SE_BIND_PROP_GET(js_cocos2dx_dragonbones_TransformObject_getOffset)

static bool js_cocos2dx_dragonbones_Slot_getRawDisplay(se::State& s)
{
    dragonBones::Slot* cobj = (dragonBones::Slot *)s.nativeThisObject();
    dragonBones::DBCCSprite* ret = static_cast<dragonBones::DBCCSprite*>(cobj->getRawDisplay());
    bool ok = native_ptr_to_seval<dragonBones::DBCCSprite>(ret, __jsb_dragonBones_DBCCSprite_class, &s.rval());
    JSB_PRECONDITION2(ok, false, "Convert dragonBones::DBCCSprite to se::Value failed!");
    return true;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_getRawDisplay)

static bool js_cocos2dx_dragonbones_Slot_getDisplay(se::State& s)
{
    dragonBones::Slot* cobj = (dragonBones::Slot *)s.nativeThisObject();
    dragonBones::DBCCSprite* ret = static_cast<dragonBones::DBCCSprite*>(cobj->getDisplay());
    bool ok = native_ptr_to_seval<dragonBones::DBCCSprite>(ret, __jsb_dragonBones_DBCCSprite_class, &s.rval());
    JSB_PRECONDITION2(ok, false, "Convert dragonBones::DBCCSprite to se::Value failed!");
    return true;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_getDisplay)

static bool js_cocos2dx_dragonbones_Slot_getMeshDisplay(se::State& s)
{
    dragonBones::Slot* cobj = (dragonBones::Slot *)s.nativeThisObject();
    dragonBones::DBCCSprite* ret = static_cast<dragonBones::DBCCSprite*>(cobj->getMeshDisplay());
    bool ok = native_ptr_to_seval<dragonBones::DBCCSprite>(ret, __jsb_dragonBones_DBCCSprite_class, &s.rval());
    JSB_PRECONDITION2(ok, false, "Convert dragonBones::DBCCSprite to se::Value failed!");
    return true;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_getMeshDisplay)

static bool js_cocos2dx_dragonbones_Slot_setDisplay(se::State& s)
{
    const auto& args = s.args();
    int argc = (int)args.size();

    if (argc == 2)
    {
        dragonBones::Slot* cobj = (dragonBones::Slot *)s.nativeThisObject();
        dragonBones::DBCCSprite* dbSprite = nullptr;
        bool ok = seval_to_native_ptr(args[0], &dbSprite);
        JSB_PRECONDITION2(ok, false, "Convert se::Value to dragonBones::DBCCSprite failed!");
        dragonBones::DisplayType type;
        ok = seval_to_int32(args[1], (int32_t *)&type);
        JSB_PRECONDITION2(ok, false, "Convert se::Value to dragonBones::DisplayType failed!");
        cobj->setDisplay(dbSprite, type);
        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_dragonbones_Slot_setDisplay)

bool register_all_dragonbones_manual(se::Object* obj)
{
    __jsb_dragonBones_Armature_proto->defineFunction("getAnimation", _SE(js_cocos2dx_dragonbones_Armature_getAnimation));
    __jsb_dragonBones_Armature_proto->defineFunction("getArmatureData", _SE(js_cocos2dx_dragonbones_Armature_getArmatureData));
    __jsb_dragonBones_Armature_proto->defineFunction("getDisplay", _SE(js_cocos2dx_dragonbones_Armature_getDisplay));

    __jsb_dragonBones_CCArmatureDisplay_proto->defineFunction("getAnimation", _SE(js_cocos2dx_dragonbones_CCArmatureDisplay_getAnimation));
    __jsb_dragonBones_AnimationState_proto->defineFunction("getAnimationData", _SE(js_cocos2dx_dragonbones_AnimationState_getAnimationData));

    __jsb_dragonBones_ArmatureData_proto->defineProperty("animations", _SE(js_cocos2dx_dragonbones_ArmatureData_get_animations), nullptr);
    __jsb_dragonBones_ArmatureData_proto->defineProperty("bones", _SE(js_cocos2dx_dragonbones_ArmatureData_get_bones), nullptr);
    __jsb_dragonBones_ArmatureData_proto->defineProperty("skins", _SE(js_cocos2dx_dragonbones_ArmatureData_get_skins), nullptr);
    __jsb_dragonBones_ArmatureData_proto->defineProperty("slots", _SE(js_cocos2dx_dragonbones_ArmatureData_get_slots), nullptr);

    __jsb_dragonBones_DragonBonesData_proto->defineProperty("armatureNames", _SE(js_cocos2dx_dragonbones_DragonBonesData_get_armatureNames), nullptr);

    se::Object* global = se::ScriptEngine::getInstance()->getGlobalObject();
    se::Value dragonBonesVal, worldClockVal;
    global->getProperty("dragonBones", &dragonBonesVal);
    dragonBonesVal.toObject()->getProperty("WorldClock", &worldClockVal);

    worldClockVal.toObject()->defineProperty("clock", _SE(js_cocos2dx_dragonbones_WorldClock_getClock), nullptr);

    __jsb_dragonBones_WorldClock_proto->defineFunction("add", _SE(js_cocos2dx_dragonbones_WorldClock_add));
    __jsb_dragonBones_WorldClock_proto->defineFunction("remove", _SE(js_cocos2dx_dragonbones_WorldClock_remove));

    se::Value factoryVal;
    dragonBonesVal.toObject()->getProperty("CCFactory", &factoryVal);
    factoryVal.toObject()->defineFunction("getFactory", _SE(js_cocos2dx_dragonbones_CCFactory_getFactory));

    __jsb_dragonBones_TransformObject_proto->defineProperty("global", _SE(js_cocos2dx_dragonbones_TransformObject_getGlobal), nullptr);
    __jsb_dragonBones_TransformObject_proto->defineProperty("origin", _SE(js_cocos2dx_dragonbones_TransformObject_getOrigin), nullptr);
    __jsb_dragonBones_TransformObject_proto->defineProperty("offset", _SE(js_cocos2dx_dragonbones_TransformObject_getOffset), nullptr);

    __jsb_dragonBones_Slot_proto->defineFunction("getRawDisplay", _SE(js_cocos2dx_dragonbones_Slot_getRawDisplay));
    __jsb_dragonBones_Slot_proto->defineFunction("getDisplay", _SE(js_cocos2dx_dragonbones_Slot_getDisplay));
    __jsb_dragonBones_Slot_proto->defineFunction("getMeshDisplay", _SE(js_cocos2dx_dragonbones_Slot_getMeshDisplay));
    __jsb_dragonBones_Slot_proto->defineFunction("setDisplay", _SE(js_cocos2dx_dragonbones_Slot_setDisplay));

    dragonBones::BaseObject::setObjectRecycleOrDestroyCallback([](dragonBones::BaseObject* obj, int type){
        se::ScriptEngine::getInstance()->clearException();
        se::AutoHandleScope hs;
        auto iter = se::__nativePtrToObjectMap.find(obj);
        if (iter != se::__nativePtrToObjectMap.end())
        {
            se::Object* seObj = iter->second;
            seObj->clearPrivateData();
            seObj->release();
        }
    });

    se::ScriptEngine::getInstance()->clearException();

    return true;
}
