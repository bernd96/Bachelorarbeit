//#line 2 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
// 
// File autogenerated for the fub_controller package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

#ifndef __fub_controller__CONTROLLERMIGPATHCONFIG_H__
#define __fub_controller__CONTROLLERMIGPATHCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace fub_controller
{
  class ControllerMigPathConfigStatics;
  
  class ControllerMigPathConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(ControllerMigPathConfig &config, const ControllerMigPathConfig &max, const ControllerMigPathConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const ControllerMigPathConfig &config1, const ControllerMigPathConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, ControllerMigPathConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const ControllerMigPathConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, ControllerMigPathConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const ControllerMigPathConfig &config) const = 0;
      virtual void getValue(const ControllerMigPathConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level, 
          std::string a_description, std::string a_edit_method, T ControllerMigPathConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T (ControllerMigPathConfig::* field);

      virtual void clamp(ControllerMigPathConfig &config, const ControllerMigPathConfig &max, const ControllerMigPathConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const ControllerMigPathConfig &config1, const ControllerMigPathConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, ControllerMigPathConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const ControllerMigPathConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, ControllerMigPathConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const ControllerMigPathConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const ControllerMigPathConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, ControllerMigPathConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, ControllerMigPathConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<ControllerMigPathConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(ControllerMigPathConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("steering_lookahead_time"==(*_i)->name){steering_lookahead_time = boost::any_cast<double>(val);}
        if("steering_min_lookahead_dist"==(*_i)->name){steering_min_lookahead_dist = boost::any_cast<double>(val);}
        if("velocity_lookahead_time"==(*_i)->name){velocity_lookahead_time = boost::any_cast<double>(val);}
        if("velocity_lookahead_dist_error_factor"==(*_i)->name){velocity_lookahead_dist_error_factor = boost::any_cast<double>(val);}
        if("velocity_max_offset"==(*_i)->name){velocity_max_offset = boost::any_cast<double>(val);}
        if("static_wanted_speed"==(*_i)->name){static_wanted_speed = boost::any_cast<double>(val);}
        if("use_static_wanted_speed"==(*_i)->name){use_static_wanted_speed = boost::any_cast<bool>(val);}
      }
    }

    double steering_lookahead_time;
double steering_min_lookahead_dist;
double velocity_lookahead_time;
double velocity_lookahead_dist_error_factor;
double velocity_max_offset;
double static_wanted_speed;
bool use_static_wanted_speed;

    bool state;
    std::string name;

    
}groups;



//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double steering_lookahead_time;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double steering_min_lookahead_dist;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double velocity_lookahead_time;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double velocity_lookahead_dist_error_factor;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double velocity_max_offset;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double static_wanted_speed;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool use_static_wanted_speed;
//#line 218 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("ControllerMigPathConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const ControllerMigPathConfig &__max__ = __getMax__();
      const ControllerMigPathConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const ControllerMigPathConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const ControllerMigPathConfig &__getDefault__();
    static const ControllerMigPathConfig &__getMax__();
    static const ControllerMigPathConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const ControllerMigPathConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void ControllerMigPathConfig::ParamDescription<std::string>::clamp(ControllerMigPathConfig &config, const ControllerMigPathConfig &max, const ControllerMigPathConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class ControllerMigPathConfigStatics
  {
    friend class ControllerMigPathConfig;
    
    ControllerMigPathConfigStatics()
    {
ControllerMigPathConfig::GroupDescription<ControllerMigPathConfig::DEFAULT, ControllerMigPathConfig> Default("Default", "", 0, 0, true, &ControllerMigPathConfig::groups);
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.steering_lookahead_time = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.steering_lookahead_time = 5.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.steering_lookahead_time = 0.5;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ControllerMigPathConfig::AbstractParamDescriptionConstPtr(new ControllerMigPathConfig::ParamDescription<double>("steering_lookahead_time", "double", 0, "time [s] to look ahead on the plan", "", &ControllerMigPathConfig::steering_lookahead_time)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ControllerMigPathConfig::AbstractParamDescriptionConstPtr(new ControllerMigPathConfig::ParamDescription<double>("steering_lookahead_time", "double", 0, "time [s] to look ahead on the plan", "", &ControllerMigPathConfig::steering_lookahead_time)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.steering_min_lookahead_dist = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.steering_min_lookahead_dist = 10.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.steering_min_lookahead_dist = 0.02;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ControllerMigPathConfig::AbstractParamDescriptionConstPtr(new ControllerMigPathConfig::ParamDescription<double>("steering_min_lookahead_dist", "double", 0, "min distance [m] to look ahead on the plan", "", &ControllerMigPathConfig::steering_min_lookahead_dist)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ControllerMigPathConfig::AbstractParamDescriptionConstPtr(new ControllerMigPathConfig::ParamDescription<double>("steering_min_lookahead_dist", "double", 0, "min distance [m] to look ahead on the plan", "", &ControllerMigPathConfig::steering_min_lookahead_dist)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.velocity_lookahead_time = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.velocity_lookahead_time = 5.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.velocity_lookahead_time = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ControllerMigPathConfig::AbstractParamDescriptionConstPtr(new ControllerMigPathConfig::ParamDescription<double>("velocity_lookahead_time", "double", 0, "time [s] to look ahead on the plan", "", &ControllerMigPathConfig::velocity_lookahead_time)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ControllerMigPathConfig::AbstractParamDescriptionConstPtr(new ControllerMigPathConfig::ParamDescription<double>("velocity_lookahead_time", "double", 0, "time [s] to look ahead on the plan", "", &ControllerMigPathConfig::velocity_lookahead_time)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.velocity_lookahead_dist_error_factor = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.velocity_lookahead_dist_error_factor = 0.5;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.velocity_lookahead_dist_error_factor = 0.01;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ControllerMigPathConfig::AbstractParamDescriptionConstPtr(new ControllerMigPathConfig::ParamDescription<double>("velocity_lookahead_dist_error_factor", "double", 0, "factor for adjusting velocity to distance between closest point in space and lookahead", "", &ControllerMigPathConfig::velocity_lookahead_dist_error_factor)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ControllerMigPathConfig::AbstractParamDescriptionConstPtr(new ControllerMigPathConfig::ParamDescription<double>("velocity_lookahead_dist_error_factor", "double", 0, "factor for adjusting velocity to distance between closest point in space and lookahead", "", &ControllerMigPathConfig::velocity_lookahead_dist_error_factor)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.velocity_max_offset = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.velocity_max_offset = 1.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.velocity_max_offset = 0.1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ControllerMigPathConfig::AbstractParamDescriptionConstPtr(new ControllerMigPathConfig::ParamDescription<double>("velocity_max_offset", "double", 0, "maximum offset to velocity in plan [m/s].", "", &ControllerMigPathConfig::velocity_max_offset)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ControllerMigPathConfig::AbstractParamDescriptionConstPtr(new ControllerMigPathConfig::ParamDescription<double>("velocity_max_offset", "double", 0, "maximum offset to velocity in plan [m/s].", "", &ControllerMigPathConfig::velocity_max_offset)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.static_wanted_speed = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.static_wanted_speed = 1.5;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.static_wanted_speed = 0.05;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ControllerMigPathConfig::AbstractParamDescriptionConstPtr(new ControllerMigPathConfig::ParamDescription<double>("static_wanted_speed", "double", 0, "static wanted speed for debug 700 rpm=0.47 m/a", "", &ControllerMigPathConfig::static_wanted_speed)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ControllerMigPathConfig::AbstractParamDescriptionConstPtr(new ControllerMigPathConfig::ParamDescription<double>("static_wanted_speed", "double", 0, "static wanted speed for debug 700 rpm=0.47 m/a", "", &ControllerMigPathConfig::static_wanted_speed)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.use_static_wanted_speed = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.use_static_wanted_speed = 1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.use_static_wanted_speed = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ControllerMigPathConfig::AbstractParamDescriptionConstPtr(new ControllerMigPathConfig::ParamDescription<bool>("use_static_wanted_speed", "bool", 0, "whether to use the static speed", "", &ControllerMigPathConfig::use_static_wanted_speed)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ControllerMigPathConfig::AbstractParamDescriptionConstPtr(new ControllerMigPathConfig::ParamDescription<bool>("use_static_wanted_speed", "bool", 0, "whether to use the static speed", "", &ControllerMigPathConfig::use_static_wanted_speed)));
//#line 246 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(ControllerMigPathConfig::AbstractGroupDescriptionConstPtr(new ControllerMigPathConfig::GroupDescription<ControllerMigPathConfig::DEFAULT, ControllerMigPathConfig>(Default)));
//#line 356 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<ControllerMigPathConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<ControllerMigPathConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<ControllerMigPathConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    ControllerMigPathConfig __max__;
    ControllerMigPathConfig __min__;
    ControllerMigPathConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const ControllerMigPathConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static ControllerMigPathConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &ControllerMigPathConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const ControllerMigPathConfig &ControllerMigPathConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const ControllerMigPathConfig &ControllerMigPathConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const ControllerMigPathConfig &ControllerMigPathConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<ControllerMigPathConfig::AbstractParamDescriptionConstPtr> &ControllerMigPathConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<ControllerMigPathConfig::AbstractGroupDescriptionConstPtr> &ControllerMigPathConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const ControllerMigPathConfigStatics *ControllerMigPathConfig::__get_statics__()
  {
    const static ControllerMigPathConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = ControllerMigPathConfigStatics::get_instance();
    
    return statics;
  }


}

#endif // __CONTROLLERMIGPATHRECONFIGURATOR_H__
