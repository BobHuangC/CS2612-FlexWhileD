"enum" {
    skip; skip; skip
}

"int" {
    n = 100;
    m = 10;
    *m = - n * n + n - n / n % n;
    m = * n - 1;
    m = -n;
    m = !n;
    n = --------m;
    n = EOF
}

"typedef" {
    **n = **(**q * (n+*****m))
}

"int_long_long" {
    while(k != ll)
    do{
        ll = ll + 1;
        k = k + *(ll)
    }
}

"char" {
    if (n == 0 || n == 1)
    then
        {n = n < 0}
    else
        {n = n > 0}
    ;
    if (m == 0 && m == 1)
    then
        {m = m == 0}
    else
        {m = m != 0}
    ;
    if (!(l == 0))
    then
        {l = l <= 0}
    else
        {l = l >= 0}
}

"*" {
    var n;
    var m;
    var aaa;
    var bbb;
    m = - n * n;
    m = * n - 1
}

"[" {
    while (n != n)
    do {
        while (l != l)
        do{
            while (m != m)
            do
            {
                m = m != m
            }
        }
    }
}

"]" {
    if (m != m && m == m)
    then {
        if (l != l || l == l)
        then {
            if ( ! k != k)
            then {
                if (! (n != n))
                then {
                    n = n + 1
                }
                else{
                    n = n - 1; skip; skip
                }
            }
            else{
                n = n - 1; skip; skip
            }
        }
        else{
            n = n - 1; skip; skip
        }
    }
    else{
        n = n - 1; skip; skip
    };
    m = 10
}

0|[1-9][0-9]* {
    while (n != n)
    do {
        if (s == s)
        then {while ( l == l + 123)
                do{
                    k = k + 1
                }
        }
        
        else {while ( l == l - 123)
                do{
                    k = k * 1; skip; skip
                }
        }
    }
}

[_A-Za-z][_A-Za-z0-9]* {
    n2 = 100;
    m2 = 10;
    m2 = - n * n;
    m2 = * n - 1
}

[\"\[]"[]\"]"[\]\"]"\"\\"[\]\"] {
    while (n != n)
    do {
        if (s == s)
        then {while ( l == l + 123)
                do{
                    k = k + 1
                }
        }
        
        else {while ( l == l - 123)
                do{
                    k = k * 1
                }
        }
    }
}

"[\}\}\{\}"[\}\"\{]"[\"\}\"\]" {
    n3 = 100;
    m3 = 10;
    m3 = - n * n;
    m3 = * n - 1
    }

"*"*"*\"*\"*"*"*" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
    }

"\\\{\\\}\\\{\{\{\{\\\}\\\{\\\\\\\{\\\\\}\\\{\\\\\\\\\{\\\}\}\\\}\}\}\{\\" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
    }

"[\[[" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
    }

"\}" {
    n = 100;
    m = 10;
    m = - n * n;
    m = * n - 1
    }


[ \t\n\r]    { };

.   {  n = 100;
  m = 10;
  m = - n * n;
  m = * n - 1 }
    


