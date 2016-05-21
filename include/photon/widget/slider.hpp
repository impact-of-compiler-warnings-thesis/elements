/*=================================================================================================
   Copyright (c) 2016 Joel de Guzman

   Licensed under a Creative Commons Attribution-ShareAlike 4.0 International.
   http://creativecommons.org/licenses/by-sa/4.0/
=================================================================================================*/
#if !defined(PHOTON_GUI_LIB_WIDGET_SLIDER_APRIL_16_2016)
#define PHOTON_GUI_LIB_WIDGET_SLIDER_APRIL_16_2016

#include <photon/widget/widget.hpp>

namespace photon
{
   ////////////////////////////////////////////////////////////////////////////////////////////////
   // Sliders
   ////////////////////////////////////////////////////////////////////////////////////////////////
   class slider : public widget
   {
   public:

      static float     knob_radius;    // fraction of size (width or height)
      static float     slot_size;      // fraction of size (width or height)

                        slider() : _pos(0) {}

      virtual rect      limits(basic_context const& ctx) const;
      virtual widget*   hit_test(context const& ctx, point p);
      virtual void      draw(context const& ctx);
      virtual widget*   click(context const& ctx, mouse_button btn);
      virtual void      drag(context const& ctx, mouse_button btn);
      virtual bool      is_control() const;

      virtual void      draw_slot(theme& thm, rect bounds, float radius);
      virtual void      draw_knob(theme& thm, float pos, rect bounds, bool hilite);
      virtual circle    knob_position(theme& thm, float pos, rect bounds);
      virtual void      draw_gauge(theme& thm, rect bounds, float radius, bool hilite);

   private:

      void              reposition(context const& ctx);
      double            _pos;
      point             _offset;
      bool              _tracking;
   };
}

#endif