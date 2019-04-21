#ifndef ID_H
#define ID_H


namespace bia
{
  class Id
  {
  private:

    unsigned int id;

  public:

    /// constroi com nada
    Id() :
      id(0)
    {}

    /// constroi com \p id
    Id (unsigned int id) :
      id(id)
    {}

    /// seta o id com \p id
    void setId (unsigned int id)
    { this->id = id; }

    /// retorna o id
    unsigned int getId () const
    { return id; }

    /// retorna o id
    operator unsigned int () const
    { return id; }

  };  /// \class Id

} /// \namespace bia

#endif // ID_H
