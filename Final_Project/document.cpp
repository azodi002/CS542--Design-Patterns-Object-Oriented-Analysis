#include "document.h"

//Template Method design pattern
void Document::executePrint()
//executes skeleton, with header for user aesthetic purposes and the article type
{
  printHeader();
  articleType();
  printHeader();
}
