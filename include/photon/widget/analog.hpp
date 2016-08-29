/*=================================================================================================   Copyright (c) 2016 Joel de Guzman   Licensed under a Creative Commons Attribution-ShareAlike 4.0 International.   http://creativecommons.org/licenses/by-sa/4.0/=================================================================================================*/#if !defined(PHOTON_GUI_LIB_WIDGET_ANALOG_AUGUST_29_2016)#define PHOTON_GUI_LIB_WIDGET_ANALOG_AUGUST_29_2016#include <photon/widget/proxy.hpp>#include <photon/widget/tracker.hpp>namespace photon{   ////////////////////////////////////////////////////////////////////////////////////////////////   // analog: class for continuous controllers.   ////////////////////////////////////////////////////////////////////////////////////////////////   class analog : public tracker   {   public:                           analog(widget_ptr indicator_, widget_ptr body_, double init_value);      virtual              ~analog();      virtual void         draw(context const& ctx);      virtual void  	      begin_tracking(context const& ctx, point start);      virtual void      	keep_tracking(context const& ctx, info& track_info);      virtual void      	end_tracking(context const& ctx, point stop);      double               value() const              { return _value; }      void                 value(double value_)       { _value = value_; }   protected:      virtual void         prepare_indicator(context& ctx);      virtual void         prepare_body(context& ctx);      virtual double       value(context const& ctx, point p) = 0;      virtual void  	      track(context const& ctx, point p);      widget_ptr           indicator() const { return _indicator; }      widget_ptr           body() const      { return _body; }   private:      double               _value;      widget_ptr           _indicator;      widget_ptr           _body;   };}#endif