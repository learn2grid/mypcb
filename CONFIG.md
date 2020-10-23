# Configuration

Follow the specification from IRB: http://lampiran1.hasil.gov.my/pdf/pdfam/FormatDataCP39BI.pdf

In the configuration file, you need to specify values for below:
- Record type for header
- Employer no. (headquarter)
- Employer no.
- Year of deduction
- Month of deduction
- Total MTD amount
- Total MTD records
- Total CP38 amount
- Total CP38 records
- Record type for detail
- Tax reference no.
- Wife code
- Employee's name
- Old IC no.
- New IC no.
- Passport no.
- Country code
- MTD amount
- CP38 amount
- Employee no. or salary no.

Example of a basic configuration file below, refer to the specification of valid values:

```
H
1234567890
1234567890
-
-
-
00001
0000000000
00000
D
1234567890
0
FOO BAR
-
750101148989
-
-
-
00000000
4242

```

