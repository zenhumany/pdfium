// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "event.h"

#include "Field.h"
#include "JS_Context.h"
#include "JS_Define.h"
#include "JS_EventHandler.h"
#include "JS_Object.h"
#include "JS_Value.h"
#include "fpdfsdk/include/javascript/IJavaScript.h"

/* -------------------------- event -------------------------- */

BEGIN_JS_STATIC_CONST(CJS_Event)
END_JS_STATIC_CONST()

BEGIN_JS_STATIC_PROP(CJS_Event)
JS_STATIC_PROP_ENTRY(change)
JS_STATIC_PROP_ENTRY(changeEx)
JS_STATIC_PROP_ENTRY(commitKey)
JS_STATIC_PROP_ENTRY(fieldFull)
JS_STATIC_PROP_ENTRY(keyDown)
JS_STATIC_PROP_ENTRY(modifier)
JS_STATIC_PROP_ENTRY(name)
JS_STATIC_PROP_ENTRY(rc)
JS_STATIC_PROP_ENTRY(richChange)
JS_STATIC_PROP_ENTRY(richChangeEx)
JS_STATIC_PROP_ENTRY(richValue)
JS_STATIC_PROP_ENTRY(selEnd)
JS_STATIC_PROP_ENTRY(selStart)
JS_STATIC_PROP_ENTRY(shift)
JS_STATIC_PROP_ENTRY(source)
JS_STATIC_PROP_ENTRY(target)
JS_STATIC_PROP_ENTRY(targetName)
JS_STATIC_PROP_ENTRY(type)
JS_STATIC_PROP_ENTRY(value)
JS_STATIC_PROP_ENTRY(willCommit)
END_JS_STATIC_PROP()

BEGIN_JS_STATIC_METHOD(CJS_Event)
END_JS_STATIC_METHOD()

IMPLEMENT_JS_CLASS(CJS_Event, event)

event::event(CJS_Object* pJsObject) : CJS_EmbedObj(pJsObject) {}

event::~event() {
}

FX_BOOL event::change(IJS_Context* cc,
                      CJS_PropValue& vp,
                      CFX_WideString& sError) {
  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  CFX_WideString& wChange = pEvent->Change();
  if (vp.IsSetting()) {
    if (vp.GetType() == CJS_Value::VT_string)
      vp >> wChange;
  } else {
    vp << wChange;
  }
  return TRUE;
}

FX_BOOL event::changeEx(IJS_Context* cc,
                        CJS_PropValue& vp,
                        CFX_WideString& sError) {
  if (!vp.IsGetting())
    return FALSE;

  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  vp << pEvent->ChangeEx();
  return TRUE;
}

FX_BOOL event::commitKey(IJS_Context* cc,
                         CJS_PropValue& vp,
                         CFX_WideString& sError) {
  if (!vp.IsGetting())
    return FALSE;

  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  vp << pEvent->CommitKey();
  return TRUE;
}

FX_BOOL event::fieldFull(IJS_Context* cc,
                         CJS_PropValue& vp,
                         CFX_WideString& sError) {
  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  if (!vp.IsGetting() &&
      wcscmp((const wchar_t*)pEvent->Name(), L"Keystroke") != 0)
    return FALSE;

  if (pEvent->FieldFull())
    vp << TRUE;
  else
    vp << FALSE;
  return TRUE;
}

FX_BOOL event::keyDown(IJS_Context* cc,
                       CJS_PropValue& vp,
                       CFX_WideString& sError) {
  if (!vp.IsGetting())
    return FALSE;

  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  if (pEvent->KeyDown())
    vp << TRUE;
  else
    vp << FALSE;
  return TRUE;
}

FX_BOOL event::modifier(IJS_Context* cc,
                        CJS_PropValue& vp,
                        CFX_WideString& sError) {
  if (!vp.IsGetting())
    return FALSE;

  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  if (pEvent->Modifier())
    vp << TRUE;
  else
    vp << FALSE;
  return TRUE;
}

FX_BOOL event::name(IJS_Context* cc,
                    CJS_PropValue& vp,
                    CFX_WideString& sError) {
  if (!vp.IsGetting())
    return FALSE;

  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  vp << pEvent->Name();
  return TRUE;
}

FX_BOOL event::rc(IJS_Context* cc, CJS_PropValue& vp, CFX_WideString& sError) {
  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  FX_BOOL& bRc = pEvent->Rc();
  if (vp.IsSetting()) {
    vp >> bRc;
  } else {
    vp << bRc;
  }
  return TRUE;
}

FX_BOOL event::richChange(IJS_Context* cc,
                          CJS_PropValue& vp,
                          CFX_WideString& sError) {
  return TRUE;
  if (vp.IsSetting()) {
  } else {
    ;
  }
  return TRUE;
}

FX_BOOL event::richChangeEx(IJS_Context* cc,
                            CJS_PropValue& vp,
                            CFX_WideString& sError) {
  return TRUE;
  if (vp.IsSetting()) {
  } else {
    ;
  }
  return TRUE;
}

FX_BOOL event::richValue(IJS_Context* cc,
                         CJS_PropValue& vp,
                         CFX_WideString& sError) {
  return TRUE;
  if (vp.IsSetting()) {
  } else {
    ;
  }
  return TRUE;
}

FX_BOOL event::selEnd(IJS_Context* cc,
                      CJS_PropValue& vp,
                      CFX_WideString& sError) {
  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  if (wcscmp((const wchar_t*)pEvent->Name(), L"Keystroke") != 0) {
    return TRUE;
  }

  int& iSelEnd = pEvent->SelEnd();
  if (vp.IsSetting()) {
    vp >> iSelEnd;
  } else {
    vp << iSelEnd;
  }
  return TRUE;
}

FX_BOOL event::selStart(IJS_Context* cc,
                        CJS_PropValue& vp,
                        CFX_WideString& sError) {
  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  if (wcscmp((const wchar_t*)pEvent->Name(), L"Keystroke") != 0) {
    return TRUE;
  }
  int& iSelStart = pEvent->SelStart();
  if (vp.IsSetting()) {
    vp >> iSelStart;
  } else {
    vp << iSelStart;
  }
  return TRUE;
}

FX_BOOL event::shift(IJS_Context* cc,
                     CJS_PropValue& vp,
                     CFX_WideString& sError) {
  if (!vp.IsGetting())
    return FALSE;

  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  if (pEvent->Shift())
    vp << TRUE;
  else
    vp << FALSE;
  return TRUE;
}

FX_BOOL event::source(IJS_Context* cc,
                      CJS_PropValue& vp,
                      CFX_WideString& sError) {
  if (!vp.IsGetting())
    return FALSE;

  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  vp << pEvent->Source()->GetJSObject();
  return TRUE;
}

FX_BOOL event::target(IJS_Context* cc,
                      CJS_PropValue& vp,
                      CFX_WideString& sError) {
  if (!vp.IsGetting())
    return FALSE;

  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  vp << pEvent->Target_Field()->GetJSObject();
  return TRUE;
}

FX_BOOL event::targetName(IJS_Context* cc,
                          CJS_PropValue& vp,
                          CFX_WideString& sError) {
  if (!vp.IsGetting())
    return FALSE;

  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  vp << pEvent->TargetName();
  return TRUE;
}

FX_BOOL event::type(IJS_Context* cc,
                    CJS_PropValue& vp,
                    CFX_WideString& sError) {
  if (!vp.IsGetting())
    return FALSE;

  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  vp << pEvent->Type();
  return TRUE;
}

FX_BOOL event::value(IJS_Context* cc,
                     CJS_PropValue& vp,
                     CFX_WideString& sError) {
  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  if (wcscmp((const wchar_t*)pEvent->Type(), L"Field") != 0)
    return FALSE;
  if (!pEvent->m_pValue)
    return FALSE;
  CFX_WideString& val = pEvent->Value();
  if (vp.IsSetting()) {
    vp >> val;
  } else {
    vp << val;
  }
  return TRUE;
}

FX_BOOL event::willCommit(IJS_Context* cc,
                          CJS_PropValue& vp,
                          CFX_WideString& sError) {
  if (!vp.IsGetting())
    return FALSE;

  CJS_Context* pContext = (CJS_Context*)cc;
  ASSERT(pContext != NULL);
  CJS_EventHandler* pEvent = pContext->GetEventHandler();
  ASSERT(pEvent != NULL);

  if (pEvent->WillCommit())
    vp << TRUE;
  else
    vp << FALSE;
  return TRUE;
}
