# C++ My Random Generate Key Encryption
Assume that we have **Order String** = **"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"** \
**Key** is random order of the string like **"qPGoscVutpTiROJUfLvrHzyxwYCWbeEKXlmjQAMZIaNDFSdknhgB"**\
To encrypt a **plain text** like **"ABxz"** encrypted text will be **"qPhB"**\
by share an index of each alphabet from **Order String** to **Key**\
encrypted[i]=Key[Order_String.find_first_of(text[i])]


