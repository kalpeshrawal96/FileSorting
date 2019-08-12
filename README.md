# FileSorting

This is File sorting inplemented in C which includes following algorithms. 

* Marking and distributing them over Source Files.
File sorting starts with marking runs. In this process we read data from raw file and write in one of the source file while creating small sorted runs.
So we keep writing to one of the source file as long as run is sorted. If any small key then previously written key is encountered then end of run is marked and we switch to another source file, vice versa.
When there is nothing to be written in source files we mark end of run and end of file.
Now source files are ready to be sorted or taken by destination file.
* 2 Source 1 Destination (2S1D)
Here 2 source files are used from Mark and Distribute Run Phase. Both source files are open and we merge 1 sorted run of from both files in destination file creating 1 sorted run from 2 sorted runs of source files. We keep doing this until all the runs from both the source files are merged and written on destination file.
After iteration, we have a destination file which has n number of sorted runs. We distribute them in 2 destination file are repeat the process until we have one run in destination file.
* 2 Source 2 Destination (2S2D)
This is similar to 2S1D but the only change is we use 2 destination files instead of 1 which saves the distribution of runs after every iteration as we are distributing them to 2 different destination in the merging process itself.
No need to distribute runs after iteration.
* Polyphase Sort
This is an algorithm which decreases the number of runs at every iteration of the main loop by merging runs into larger runs. It is used for external sorting.
 In this type of sort, the source files being merged, and the destination file to which the merged sub files are written, vary continuously throughout the sort. In this technique, the concept of a pass through records is not as clear-cut as in the straight or the natural merge.
At the start of each iteration, there will be two input files and one output file. At the end of the iteration, one input file will have been completely consumed and will become the output file for the next iteration. The current output file will become an input file for the next iteration. The remaining files (just one in the 3 file case) have only been partially consumed and their remaining runs will be input for the next iteration.


File 1 just emptied and became the new output file. One run is left on each input tape, and merging those runs together will make the sorted file.

File 1 (out):                                           <1 run> *        (the sorted file)

File 2 (in ): ... | <1 run> *               -->     ... <1 run> | *          (consumed)

File 3 (in ):     | <1 run> *                           <1 run> | *          (consumed)


possible runs that have already been read marked by ...  

the read pointer of the file marked by |    

end of file marked by *    


Stepping back to the previous iteration, we were reading from 1 and 2. One run is merged from 1 and 2 before file 1 goes empty. Notice that file 2 is not completely consumed—it has one run left to match the final merge (above).

File 1 (in ): ... | <1 run> *                      ... <1 run> | *

File 2 (in ):     | <2 run> *           -->            <1 run> | <1 run> *

File 3 (out):                                          <1 run> *


Stepping back another iteration, 2 runs are merged from 1 and 3 before file 3 goes empty.

File 1 (in ):     | <3 run>                        ... <2 run> | <1 run> *

File 2 (out):                               -->        <2 run> *

File 3 (in ): ... | <2 run> *                          <2 run> | *


Stepping back another iteration, 3 runs are merged from 2 and 3 before file 2 goes empty.

File 1 (out):                                          <3 run> *

File 2 (in ): ... | <3 run> *               -->    ... <3 run> | *

File 3 (in ):     | <5 run> *                          <3 run> | <2 run> *


Stepping back another iteration, 5 runs are merged from 1 and 2 before file 1 goes empty.

File 1 (in ): ... | <5 run> *                      ... <5 run> | *

File 2 (in ):     | <8 run> *               -->        <5 run> | <3 run> *

File 3 (out):                                          <5 run> *

