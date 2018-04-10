// ScreenResource.cc for Fluxbox Window Manager
// Copyright (c) 2015 - Mathias Gumz <akira@fluxbox.org>
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#include "ScreenResource.hh"
#include "FbTk/Util.hh"
#include "fluxbox.hh"
#include <cstring>

namespace {

struct TabPlacementString {
  FbWinFrame::TabPlacement placement;
  const char *str;
};

const TabPlacementString _PLACEMENT_STRINGS[] = {
    {FbWinFrame::TOPLEFT, "TopLeft"},
    {FbWinFrame::TOP, "Top"},
    {FbWinFrame::TOPRIGHT, "TopRight"},
    {FbWinFrame::BOTTOMLEFT, "BottomLeft"},
    {FbWinFrame::BOTTOM, "Bottom"},
    {FbWinFrame::BOTTOMRIGHT, "BottomRight"},
    {FbWinFrame::LEFTBOTTOM, "LeftBottom"},
    {FbWinFrame::LEFT, "Left"},
    {FbWinFrame::LEFTTOP, "LeftTop"},
    {FbWinFrame::RIGHTBOTTOM, "RightBottom"},
    {FbWinFrame::RIGHT, "Right"},
    {FbWinFrame::RIGHTTOP, "RightTop"}};
}

namespace FbTk {

template <>
std::string FbTk::Resource<FbWinFrame::TabPlacement>::getString() const {

  size_t i = (m_value == FbTk::Util::clamp(m_value, FbWinFrame::TOPLEFT,
                                           FbWinFrame::RIGHTTOP)
                  ? m_value
                  : FbWinFrame::DEFAULT) -
             1;
  return _PLACEMENT_STRINGS[i].str;
}

template <>
void FbTk::Resource<FbWinFrame::TabPlacement>::setFromString(
    const char *strval) {

  size_t i;
  for (i = 0; i < sizeof(_PLACEMENT_STRINGS) / sizeof(_PLACEMENT_STRINGS[0]);
       ++i) {
    if (strcasecmp(strval, _PLACEMENT_STRINGS[i].str) == 0) {
      m_value = _PLACEMENT_STRINGS[i].placement;
      return;
    }
  }
  setDefaultValue();
}

} // end namespace FbTk

ScreenResource::ScreenResource(FbTk::ResourceManager &rm,
                               const std::string &scrname,
                               const std::string &altscrname)
    : opaque_move(rm, true, "desktop.opaqueMove", ""),
      full_max(rm, false, "window.maximize.full", ""),
      max_ignore_inc(rm, true, "window.maximize.ignoreIncrement", ""),
      max_disable_move(rm, false, "window.maximize.disableMove", ""),
      max_disable_resize(rm, false, "window.maximize.disableResize", ""),
      workspace_warping(rm, true, "workspace.warp.enabled", ""),
      workspace_warping_vertical(rm, true, "workspace.warp.vertical", ""),
      show_window_pos(rm, false, "osd.showWindowPosition", ""),
      auto_raise(rm, true, "desktop.autoRaise", ""),
      click_raises(rm, true, "desktop.clickRaises", ""),
      default_deco(rm, "NORMAL", "window.deco", ""),
      tab_placement(rm, FbWinFrame::TOPLEFT, "window.tab.placement", ""),
      windowmenufile(rm,
                     Fluxbox::instance()->getDefaultDataFilename("windowmenu"),
                     "file.windowMenu", ""),
      typing_delay(rm, 0, "session.noFocusWhileTypingDelay", ""),
      workspaces(rm, 4, "workspace.amount", ""),
      edge_snap_threshold(rm, 10, "window.snap.moveThreshold", ""),
      edge_resize_snap_threshold(rm, 0, "window.snap.resizeThreshold", ""),
      focused_alpha(rm, 255, "window.alpha.focus", ""),
      unfocused_alpha(rm, 255, "window.alpha.unfocus", ""),
      menu_alpha(rm, 255, "menu.alpha", ""),
      menu_delay(rm, 200, "menu.delaySub", ""),
      tab_width(rm, 64, "window.tab.width", ""),
      tooltip_delay(rm, 500, "desktop.tooltipDelay", ""),
      workspace_warping_vertical_offset(rm, 1, "workspace.warp.verticalOffset",
                                        ""),
      allow_remote_actions(rm, false, "session.allowRemoteAction", ""),
      clientmenu_use_pixmap(rm, true, "desktop.clientMenu.usePixmap", ""),
      tabs_use_pixmap(rm, true, "window.tab.usePixmap", ""),
      max_over_tabs(rm, false, "window.tab.maxOver", ""),
      default_internal_tabs(rm, true /* TODO: autoconf option? */,
                            "window.tab.intitlebar", "") {}
