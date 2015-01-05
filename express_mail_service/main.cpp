#include "express_mail.h"
int main()
{
    express_mail *e = new express_mail();
    e->input_packages_list(e);
    e->output_packages_list(e);

}
