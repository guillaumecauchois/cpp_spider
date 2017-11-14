/*
** SerializeHandler.hpp for cpp_spider in /home/guillobits/Projects/epitech/tek3/cpp_spider/inc/common/SerializeHandler.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Nov 02 09:25:35 2017 Guillaume CAUCHOIS
** Last update Thu Nov 02 09:25:35 2017 Guillaume CAUCHOIS
*/

#ifndef		_SERIALIZE_HANDLER__HPP_
# define	_SERIALIZE_HANDLER__HPP_
# include "Event.hpp"
# include <boost/serialization/export.hpp>
# include <boost/archive/text_iarchive.hpp>
# include <boost/archive/text_oarchive.hpp>
# include <boost/serialization/vector.hpp>
# include <boost/serialization/access.hpp>
# include <boost/serialization/string.hpp>
# include <boost/serialization/shared_ptr.hpp>
# include <boost/serialization/serialization.hpp>
# include <ostream>
# include <iostream>

class SerializeHandler
{
public:
  SerializeHandler() {};
  virtual ~SerializeHandler() {};

  /**
   * Serializer
   * @tparam Obj : Represent a type to be serialize (type of obj)
   * @param obj : The object to be seralize
   * @param the serialize string
   */
  template <class Obj>
  static std::string	serializeObj(Obj &obj)
  {
    std::ostringstream			archive_stream;
    {
      boost::archive::text_oarchive	archive(archive_stream);
      archive << obj;
    }

    std::string	test = archive_stream.str();
    return archive_stream.str();
  }

  /**
   * DeSerializer
   * @tparam Obj : Represent the end type return
   * @param buf : The buffer need be deserialize
   * @return : The new object made by deserialization
   */
  template <class Obj>
  static void	deserialize(Obj & obj, const std::string &buf)
  {
    std::istringstream			archive_stream(buf);
    {
      boost::archive::text_iarchive archive(archive_stream);
      archive >> obj;
    }
  }
};

#endif		/* !_SERIALIZE_HANDLER__HPP_! */
