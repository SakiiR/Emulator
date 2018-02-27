#include "resource.h"
#include "debugger/breakpoint.h"

char                    init_breakpoints(t_breakpoint **breakpoints)
{
  *breakpoints = NULL;
  return RETURN_SUCCESS;
}

char                    add_breakpoint(t_breakpoint **breakpoints, uint16_t address)
{
  t_breakpoint          *it = *breakpoints;
  t_breakpoint          *e = NULL;

  if ((e = malloc(sizeof(*e))) == NULL)
    return RETURN_FAILURE;
  e->next = NULL;
  e->address = address;
  if (*breakpoints == NULL)
  {
    e->prev = NULL;
    *breakpoints = e;
    return RETURN_SUCCESS;
  }
  while (it && it->next)
    it = it->next;
  it->next = e;
  e->prev = it;
  return RETURN_SUCCESS;
}

char                    delete_breakpoint(t_breakpoint **breakpoints, uint16_t address)
{
  t_breakpoint          *it = *breakpoints;

  while (it)
  {
    if (it->address == address) /* Should remove it */
    {
      if (it->prev == NULL)     /* first node */
        *breakpoints = it->next;
      else /* Middle node */
        it->prev->next = it->next;
      free(it);
    }
    it = it->next;
  }
  return RETURN_SUCCESS;
}
