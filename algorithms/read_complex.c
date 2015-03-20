static void input(basic_istream_char *this, char **input_string)
{
    struct {
        basic_ostringstream_char obj;
        basic_ios_char vbase;
    } oss;
    locale loc;
    basic_string_char st;
    MSVCP_size_t length;
    const char *temp;
    ios_base *ostringstream_ios_base, *ostream_ios_base;
    basic_ostringstream_char_ctor(&oss.obj);
    ostream_ios_base = &basic_istream_char_get_basic_ios(this)->base;
    ostringstream_ios_base = &oss.vbase.base;
    if(basic_istream_char_sentry_create(this, FALSE)) {
        MSVCP_basic_string_char_ctor(&st);
        basic_istream_char_getline_bstr(this, &st);

        ios_base_imbue(ostringstream_ios_base, &loc, ostream_ios_base->loc);
        locale_dtor(&loc);
        basic_ostream_char_print_bstr(&oss.obj.base, &st);
        basic_ostringstream_char_str_get(&oss.obj, &st);

        length = MSVCP_basic_string_char_length(&st);
        free(*input_string);
        *input_string = malloc(length+1);
        temp = MSVCP_basic_string_char_c_str(&st);
        strcpy(*input_string, temp);
        MSVCP_basic_string_char_dtor(&st);
        ios_base_clear(&basic_istream_char_get_basic_ios(this)->base, IOSTATE_goodbit);//clear eof bit
    }else {
        if(! *input_string) {
            *input_string = malloc(1);
            **input_string = '\0';
        }
       // printf("input fail\n");
    }
    basic_istream_char_sentry_destroy(this);
//    basic_ios_char_setstate(basic_istream_char_get_basic_ios(this), IOSTATE_goodbit);
//    printf("\n\ninput state is %x", ios_base_rdstate(&(base->base)));
}

static BOOL check_expression(char *input_string, int i, int *char_count, int *other, int *number)
{
    enum OPERATOR{left_parenthesis, comma, decimal_point};
    int pre_number = 0;
    char_count[comma] = char_count[decimal_point] = 0;
    while(input_string[i]) {
        if(input_string[i]==' ' || input_string[i]=='\t'|| input_string[i]=='-'|| input_string[i]=='+'
                || input_string[i]=='(' || input_string[i]=='.' || input_string[i]==','
                || input_string[i]=='E'|| input_string[i]=='e') {
            switch(input_string[i]) {
                case '\t': break;
                case ' ':  break;
                case '(': ++char_count[left_parenthesis]; break;
                case ',':
                          if(*number<1 || char_count[decimal_point]>1) {//etc:(++3,12),(4..4,1)
                              printf("break at ','");
                              return FALSE;
                          }else {//recount . and number "+, - , ." from ,
                              char_count[decimal_point]= 0;
                              pre_number = *number;
                          }
                          ++char_count[comma];
                          break;//next level's analyse, after ,  reset all
                case '.': ++char_count[decimal_point]; break;
                case '+': case '-':
                          if(isdigit(input_string[i+1])|| input_string[i+1]=='.')//(input_string[i+1]>='0'&&input_string[i+1]<='9') 
                              break;
                          else
                              return FALSE;
                case 'E': case 'e':
                          if(isdigit(input_string[i+1]))
                              if(isdigit(input_string[i-1]))
                                  ++i;
                          break;
            }
        }else if(input_string[i] == ')') {
            pre_number = *number;//record (12) pre_number
            if(pre_number < 1) {
                printf("pre_number<1");//etc:(12)
                return FALSE;
            }
            break; //etc:(12,4)&^         2
        }else if(isdigit(input_string[i])) {
            ++*number;
        }else {
            ++*other;
        }
        ++i;
    }
    if(char_count[left_parenthesis]>1 || char_count[comma]>1 || char_count[decimal_point]>1) {
        //false format:((3.12,3),(9,,3)
        printf("char count ;");
        return FALSE;
    }
    return TRUE;
}

/* ??$?5NDU?$char_traits@D@std@@@std@@YAAAV?$basic_istream@DU?$char_traits@D@std@@@0@AAV10@AAV?$complex@N@0@@Z */
/* ??$?5DU?$char_traits@D@std@@@std@@YAAEAV?$basic_istream@DU?$char_traits@D@std@@@0@AEAV10@AEAV?$complex@N@0@@Z */
basic_istream_char* __cdecl basic_istream_char_read_complex_double(basic_istream_char *this, complex_double *v)
{
    char *input_string;
    basic_ios_char *base = basic_istream_char_get_basic_ios(this);
    int state = IOSTATE_goodbit;
    int number = 0, other = 0, i = 0;
    int char_count[3] = {0};
    char start = ' ', middle = ' ', end = ' ';
    complex_double temp;
    enum OPERATOR{left_parenthesis, comma, decimal_point};
    TRACE("(%p %p)\n", this, v);
    input_string = NULL;
    input(this, &input_string);

    sscanf(input_string, " %c %lf %c %lf %c", &start, &temp.real, &middle, &temp.imag, &end);
    printf("\ninput string is :  %s\n ", input_string);
    printf("\nstart is : %c\nreal is : %lf\nmiddle is : %c\nimag is : %lf\nend is : %c\n", start,temp.real,middle,temp.imag,end);
    if((start>='0' && start<='9') || start=='+' || start=='-' || start=='.') {//3.12,12  or +
        while(input_string[i] != start)
            ++i;
        if(start=='+' || start=='-') {
            if(input_string[i+1]!=' ' && input_string[i+1]!='\t' && input_string[i+1])//+12,a  or ++12,3
                if(input_string[i+1]=='+' || input_string[i+1]=='-')
                    state |= IOSTATE_failbit;
                else
                    start = ' ';
            else if(input_string[i+1] == '\0')
                state = IOSTATE_failbit|IOSTATE_eofbit;
            else
                state |= IOSTATE_failbit;
        }
        if(start!='+' && start!='-') {//.3,56 or 12,3)
            sscanf(input_string, " %lf", &temp.real);
            printf("number part 2\n");
            v->real = temp.real;
            v->imag = 0;
            while(input_string[i] != '\0') {
                if(! isdigit(input_string[i]))
                    if(input_string[i]!='+'&& input_string[i]!='-'&&input_string[i]!='.'
                            && input_string[i]!='e' && input_string[i]!='E')
                        break;
                ++i;
            }
            if(input_string[i] == '\0')
                state = state|IOSTATE_eofbit;
        }
    }else if(start == '(') {
        while(input_string[i] != start)
            ++i;
        if(! check_expression(input_string, i, char_count, &other, &number)) {
            basic_ios_char_setstate(base, state|IOSTATE_failbit);
            free(input_string);
            return this;
        }
        if(other == 0) {
            if(number == 0) {
                printf("seems like (   (,)\n");
                if(char_count[comma]==1 || char_count[decimal_point]==1) {//12,.  (,) (+)
                    basic_ios_char_setstate(base, state|IOSTATE_failbit);
                    free(input_string);
                    return this;
                }

                input(this, &input_string);//(  or   *
                if(! check_expression(input_string, 0, char_count, &other, &number)) {
                    basic_ios_char_setstate(base, state|IOSTATE_failbit);
                    free(input_string);
                    return this;
                }
                if(number < 1) {
                    printf("number<1 break\n");
                    basic_ios_char_setstate(base, state|IOSTATE_failbit);
                    free(input_string);
                    return this;
                }

                sscanf(input_string, " %lf %c %lf %c", &temp.real, &middle, &temp.imag, &end);
                printf("\nstart is : %c\nreal is : %lf\nmiddle is : %c\nimag is : %lf\nend is : %c\n", start,temp.real,middle,temp.imag,end);
            }
        }else {
            basic_ios_char_setstate(base, state|IOSTATE_failbit);
            printf("break: (*&, other is %d\n", other);
            free(input_string);
            return this;
        }

        if(middle == ' ') {
            input(this, &input_string);
            sscanf(input_string, " %c %lf %c", &middle, &temp.imag, &end);
            printf("middle is : %c\n", middle);
        }
        if(middle == ')') {
            v->real = temp.real;//etc:(12)
            v->imag = 0;
            basic_ios_char_setstate(base, state);
            free(input_string);
            return this;
        }else if(middle != ',') {
            basic_ios_char_setstate(base, state|IOSTATE_failbit);
            free(input_string);
            return this;
        }

        i = 0, number = 0, other = 0;
        while(input_string[i] != ',') {
            if(! input_string[i]) {// == '\0'
                i = -1;
                break;
            }
            ++i;
        }
        if(! check_expression(input_string, i+1, char_count, &other, &number)) {
            basic_ios_char_setstate(base, state|IOSTATE_failbit);
            free(input_string);
            return this;
        }

        if(other == 0) {
            if(number == 0) {
                if(char_count[decimal_point] != 0) {
                    printf("\nlike (12,.\n");
                    free(input_string);
                    basic_ios_char_setstate(base, IOSTATE_eofbit |IOSTATE_failbit);
                    return this;
                }
                printf("seems like (12,\n");
                input(this, &input_string);
                sscanf(input_string, " %lf %c", &temp.imag, &end);
                if(! check_expression(input_string, 0, char_count, &other, &number)) {
                    printf("\ncheck_expression3 break!!!");
                    basic_ios_char_setstate(base, state|IOSTATE_failbit);
                    free(input_string);
                    return this;
                }
                if(other > 0) {
                    basic_ios_char_setstate(base, state|IOSTATE_failbit);
                    free(input_string);
                    printf("\nother>0 break!!!");
                    return this;
                }
                printf("\nstart is : %c\nreal is : %lf\nmiddle is : %c\nimag is : %lf\nend is : %c\n", start,temp.real,middle,temp.imag,end);
            }
        }else {
            basic_ios_char_setstate(base, state|IOSTATE_failbit);
            free(input_string);
            printf("break: (12,*&,other is %d\n", other);
            return this;
        }

        if(end == ' ') {
            input(this, &input_string);
            sscanf(input_string, " %c", &end);
            printf("\nstart is : %c\nreal is : %lf\nmiddle is : %c\nimag is : %lf\nend is : %c\n", start,temp.real,middle,temp.imag,end);
        }
        if(end != ')') {//(3.12,12\n *
            state |= IOSTATE_failbit;
            printf("Progress 1!!No operation!\n");
            while(input_string[i]) {
                //printf("i:%d,: %c\n", i, input_string[i]);
                if((input_string[i]=='e' || input_string[i]=='E') && input_string[i+1]==' ')
                    break;
                else
                    ++i;
            }
            if(input_string[i] != '\0')
                ios_base_clear(&basic_istream_char_get_basic_ios(this)->base, IOSTATE_failbit);
        }else {//(3.12)
            state = IOSTATE_goodbit;
            printf("Progress 3!!assign value!\n");
            v->real = temp.real;
            v->imag = temp.imag;
        }

    }else {// *
        state |= IOSTATE_failbit;
        printf("progress !4!!!\n");
    }

    free(input_string);
//printf("origin: state is %x\n", state);
//printf("final1: state is %x\n", ios_base_rdstate(&(base->base)));
    basic_ios_char_setstate(base, state);
    return this;
}


