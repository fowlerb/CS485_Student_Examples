#include "PacString.h"
#include <utility>

PacString::PacString ()
{
  //std::cout << "default ctor\n";
}

PacString::PacString (const char *pszString)
{
  //std::cout << "const char * param ctor\n";
  int stringSize = strlen (pszString) + 1;

  mpszData = new char[stringSize] ();

  for (int i = 0; i < stringSize; i++)
  {
    mpszData[i] = pszString[i];
  }

}

PacString::PacString (const PacString &rcData)
{
  //std::cout << "PacString param ctor\n";
  mpszData = rcData.mpszData;
}

PacString::~PacString ()
{
  //std::cout << "dtor\n";
  delete mpszData;
}


PacString& PacString::operator=(PacString rcData)
{
  //std::cout << "operator =\n";
  mpszData = rcData.mpszData;
  return *this;
}

std::ostream& operator<<(std::ostream &out, const PacString &rcData)
{
  //std::cout << "operator <<\n";
  if (nullptr != rcData.mpszData)
  {
    out << rcData.mpszData;
  }
  else
  {
    out << "nullptr";
  }
  return out;
}