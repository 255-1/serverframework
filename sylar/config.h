//
// Created by zhi-jun on 22-8-8.
//

#ifndef SYLAR_CONFIG_H
#define SYLAR_CONFIG_H

#include <string>
#include <memory>
#include <sstream>
#include <boost/lexical_cast.hpp>

namespace sylar{

    class ConfigVarBase{
    public:
        typedef std::shared_ptr<ConfigVarBase> ptr;
        ConfigVarBase(const std::string& name, const std::string& description = "")
            :m_name(name)
            ,m_description(description){
        }

        virtual ~ConfigVarBase(){}

        const std::string& getName() const {return m_name;}
        const std::string& getDescription() const {m_description;}

        virtual std::string toString() = 0;
        virtual bool fromString(const std::string& val) = 0;

    protected:
        std::string m_name;
        std::string m_description;

    };


    template<class T>
    class ConfigVar : public ConfigVarBase{
    public:
        typedef std::shared_ptr<ConfigVar> ptr;

        ConfigVar(const std::string& name
                  ,const T& default_value
                  ,const std::string& description = "")
              :ConfigVarBase(name, description)
              ,m_val(default_value)
         {}
    private:
        T m_val;
    };

}

#endif //SYLAR_CONFIG_H
