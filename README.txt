Για την υλοποίηση της άσκησης ακολούθησα τα βήματα της εκφώνησης και του φροντιστηρίου.

Έκανα τις ίδιες αλλαγές στα αρχεία του Linux για να δημιουργηθούν τα 2 νεα system_calls get
και set. Οι αλλαγές ήταν ακριβώς ανάλογες όπως το dummy παράδειγμα. Να σημειωθεί πως στο
path : linux- 2.6.38.1/include/linux/ ,δημιούργησα ενα header file : d_params.h για να έχει το type
definition του struct d_params που το χρειαζόμαστε για την get.


Στην set ελέγχω απλώς αν το group_name είναι κεφαλαίο (με ASCII) και το member_id
να είναι μεγαλύτερο του 0. Η get ωστόσο ελέγχει απλώςαν είναι Null ο pointer ορίσματος 
και στην συνέχεια γεμίζει το struct του κατάλληλα με τις τιμές που υπάρχουν
στα πεδία του task_struct της διεργασίας που επέστρεψε η get_current. 

Αρχικά έκανα define τους αριθμούς των νέων system calls στο unistd_32.h και αύξησα
τον συνολικό αριθμό των system calls κατά 2. Στην συνέχεια έδωσα την πληροφορία στον kernel για τα νέα system
calls μέσω του syscall_table_32.S (όπου προσθέτουμε 2 entries το τέλος της λίστας). Μετά επεξεργαζόμαστε το 
syscalls.h προσθέτοντας το signature του κάθε system call. Έπειτα δημιούργησα ενα header file : d_params.h
στο path : linux- 2.6.38.1/include/linux (για να έχει το type definition του struct d_params που το 
χρειαζόμαστε για την get).Τέλος δημιουργησα 2 .c αρχεία, ένα για το κάθε system call μέσα στον kernel 
με τον ορισμό της αντίστοιχης συνάρτησης.


Στον qemu εφόσον χρησιμοποιήσουμε το image που παράχθηκε από το compilation του kernel
απλώς πρόσθεσα στο unistd.h (απο root) το definition του struct d_params.

Για να δημιουργήσετε τα εκτελέσιμα "test1.out" και "test2.out", απλώς εκτελέστε την εντολή make ή make all.
Για να εκτελέσετε το "test1.out", χρησιμοποιήστε την εντολή make run_test1.
Για να εκτελέσετε το "test2.out", χρησιμοποιήστε την εντολή make run_test2.



