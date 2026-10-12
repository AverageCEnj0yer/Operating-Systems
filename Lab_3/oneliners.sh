# Q1. How many requests failed?
grep -i "FAIL" access.log | wc -l
# Q2. How many different pages were requested, and which?
cut -d'/' -f2 access.log | sort -u | awk '{print; count++} END {print "\nTotal
pages:", count}'
# Q3. How many requests did each page get?
cut -d'/' -f2 access.log | sort | uniq -c
# Q4. Which user or users have the most failed requests, and how many?
grep -i 'fail' access.log | cut -d' ' -f3 | sort | uniq -c | sort -r
# Q5. How many requests did user3 make, and how many of them failed?
data=$(grep "user3" access.log) ; echo "Nr commands: $(echo "$data" | wc -l)"
; echo "failed: $(echo "$data" | grep -c "FAIL")"
# Q6. Print the last 3 failed requests, showing only time and user.
grep "FAIL" access.log | tail -n 3 | cut -d' ' -f2,3
# Q7. Which login shells appear in /etc/passwd, and how many accounts use each?
cut -d':' -f7 /etc/passwd | sort | uniq -c
