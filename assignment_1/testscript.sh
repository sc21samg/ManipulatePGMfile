#Test script

##############################################################
echo " "
#Test script for pgmEcho
echo "Test script for pgmEcho"
#1. Ascii file 
echo "Echoing Ascii file slice0a.pgm to out0.pgm"
./pgmEcho images/slice0a.pgm out0.pgm

#2. Bad Argument Count
echo "Echoing Bad Argument Count slice1a.pgm to nothing"
./pgmEcho images/slice1a.pgm

#3. Bad File Name
echo "Echoing Bad File Name slicea.pgm to out2.pgm" 
./pgmEcho images/slicea.pgm out2.pgm

#4. Bad Magic Number
echo "Echoing Bad Magic Number slice3a.pgm to out3.pgm"
./pgmEcho images/slice3a.pgm out3.pgm

#5. Bad Dimensions
echo "Echoing Bad Dimensions slice4a.pgm to out4.pgm"
./pgmEcho images/slice4a.pgm out4.pgm

#6. Bad Max Gray Value
echo "Echoing Bad Max Gray Value slice5a.pgm to out5.pgm"
./pgmEcho images/slice5a.pgm out5.pgm

#7. Bad Data
echo "Echoing Bad Data slice6a.pgm to out6.pgm"
./pgmEcho images/slice6a.pgm out6.pgm

#8. identical binary file to baboon.pgm to make out8.pgm
echo "Echoing Binary file baboon.pgm to out8.pgm"
./pgmEcho images/baboon.pgm out8.pgm

#8.1. diff Compare identical binary images 
echo "Echoing diff compare identical binary file baboon.pgm to out8.pgm"
diff images/baboon.pgm out8.pgm

#Deleting pgmEcho temporary files
echo "Deleting pgmEcho temporary files"
rm out0.pgm out3.pgm out4.pgm out5.pgm out6.pgm out8.pgm 


##############################################################
echo " "
#Test script for pgmComp
echo "Test script for pgmComp"
#1. Compare identical ascii images
echo "Echoing compare identical ascii file slice0a.pgm to slice1a.pgm"
./pgmComp images/slice0a.pgm images/slice1a.pgm

#1.1. diff Compare identical ascii images 
echo "Echoing diff compare identical ascii file slice0a.pgm to slice1a.pgm"
diff images/slice0a.pgm images/slice1a.pgm

#2. Bad Argument Count
echo "Echoing Bad Argument Count slice1a.pgm to slice1a.pgm"
./pgmComp images/slice1a.pgm 

#3. Bad File Name
echo "Echoing Bad File Name slicea.pgm to slice1a.pgm"
./pgmComp images/slicea.pgm images/slice1a.pgm

#4. Bad Magic Number
echo "Echoing Bad Magic Number slice3a.pgm to slice1a.pgm"
./pgmComp images/slice3a.pgm images/slice1a.pgm

#5. Bad Dimensions
echo "Echoing Bad Dimensions slice4a.pgm to slice1a.pgm"
./pgmComp images/slice4a.pgm images/slice1a.pgm

#6. Bad Max Gray Value
echo "Echoing Bad Max Gray Value slice5a.pgm to slice1a.pgm"
./pgmComp images/slice5a.pgm images/slice1a.pgm

#7. Bad Data
echo "Echoing Bad Data slice6a.pgm to slice1a.pgm"
./pgmComp images/slice6a.pgm images/slice1a.pgm

#8. Compare identical binary images 
echo "Echoing compare identical binary file baboon.pgm to baboon1.pgm"
./pgmComp images/baboon.pgm images/baboon1.pgm

#8.1. Diff Compare identical binary images 
echo "Echoing diff compare identical binary file baboon.pgm to baboon1.pgm"
diff images/baboon.pgm images/baboon1.pgm

#9. Compare non identical binary images 
echo "Echoing compare non identical binary file baboon.pgm to bird.pgm"
./pgmComp images/baboon.pgm images/bird.pgm

#9.1. Diff Compare non identical binary images 
#echo "Echoing diff compare non identical ascii file baboon.pgm to bird.pgm"
#diff images/baboon.pgm images/bird.pgm

#10. Compare non identical ascii images
echo "Echoing compare non identical ascii file slice0a.pgm to slice1a.pgm"
./pgmComp images/slice0a.pgm images/baboon.ascii.pgm

#10.1. Diff Compare non identical ascii images
#echo "Echoing diff compare non identical ascii file slice0a.pgm to slice1a.pgm"
#diff images/slice0a.pgm images/baboon.ascii.pgm

#11. Compare identical binary ascii images 
echo "Echoing compare identical binary ascii file baboon.pgm to baboon1.pgm"
./pgmComp images/baboon.pgm images/baboon.ascii.pgm

#11.1. Diff Compare identical binary ascii images 
#echo "Echoing diff compare identical binary ascii file baboon.pgm to baboon1.pgm"
#diff images/baboon.pgm images/baboon.ascii.pgm

#12. Compare non identical binary ascii images 
echo "Echoing compare non identical binary ascii file baboon.pgm to slice0a.pgm"
./pgmComp images/baboon.pgm images/slice0a.pgm

#12.1. Diff Compare non identical binary images 
#echo "Echoing diff compare non identical ascii file baboon.pgm to bird.pgm"
#diff images/baboon.pgm images/bird.pgm



##############################################################
echo " "
#Test script for pgma2b
echo "Test script for pgma2b"
#1. Ascii image to Binary image
echo "Echoing Ascii image to Binary image slice0a.pgm to out0.pgm"
./pgma2b images/slice0a.pgm out0.pgm

#2. Bad Argument Count
echo "Echoing Bad Argument Count slice1a.pgm to "
./pgma2b images/slice1a.pgm

#3. Bad File Name
echo "Echoing Bad File Name slicea.pgm to out2.pgm"
./pgma2b images/slicea.pgm out2.pgm

#4. Bad Magic Number
echo "Echoing Bad Magic Number slice3a.pgm to out3.pgm"
./pgma2b images/slice3a.pgm out3.pgm

#5. Bad Dimensions
echo "Echoing Bad Dimensions slice4a.pgm to out4.pgm"
./pgma2b images/slice4a.pgm out4.pgm

#6. Bad Max Gray Value
echo "Echoing Bad Max Gray Value slice5a.pgm to out5.pgm"
./pgma2b images/slice5a.pgm out5.pgm

#7. Bad Data
echo "Echoing Bad Data slice6a.pgm to out6.pgm"
./pgma2b images/slice6a.pgm out6.pgm

#8. Binary image to Binary image
echo "Echoing Binary image to Binary image baboon.pgm to out8.pgm"
./pgma2b images/baboon.pgm out8.pgm

#Deleting pgma2b temporary files
echo "Deleting pgma2b temporary files"
rm  out0.pgm out3.pgm out4.pgm out5.pgm out6.pgm out8.pgm 


##############################################################
echo " "
#Test script for pgmb2a
echo "Test script for pgmb2a"
#1. Binary image to Ascii image
echo "Echoing Binary image to Ascii image image baboon.pgm to out0.pgm"
./pgmb2a images/baboon.pgm out0.pgm

#2. Bad Argument Count
echo "Echoing Bad Argument Count baboon1a.pgm to out1.pgm"
./pgmb2a images/baboon1a.pgm

#3. Bad File Name
echo "Echoing Bad File Name baboon2aa.pgm to out2.pgm"
./pgmb2a images/baboon2aa.pgm out2.pgm

#4. Bad Magic Number
echo "Echoing Bad Magic Number baboon3a.pgm to out3.pgm"
./pgmb2a images/baboon3a.pgm out3.pgm

#5. Bad Dimensions
echo "Echoing Bad Dimensions baboon4a.pgm to out4.pgm"
./pgmb2a images/baboon4a.pgm out4.pgm

#6. Bad Max Gray Value
echo "Echoing Bad Max Gray Value baboon5a.pgm to out5.pgm"
./pgmb2a images/baboon5a.pgm out5.pgm

#7. Bad Data
echo "Echoing Bad Data baboon6a.pgm to out6.pgm"
./pgmb2a images/baboon6a.pgm out6.pgm

#8. Ascii image to Ascii image
echo "Echoing Ascii image to Ascii image slice0a.pgm to out8.pgm"
./pgmb2a images/slice0a.pgm out8.pgm

#Deleting pgmb2a temporary files
echo "Deleting pgmb2a temporary files"
rm out0.pgm out3.pgm out4.pgm out5.pgm out6.pgm out8.pgm 



##############################################################
echo " "
#Test script for pgmReduce
echo "Test script for pgmReduce"
#1. Reduce ascii file 
echo "Echoing Reduce ascii file baboon.ascii.pgm to out0.pgm" 
./pgmReduce images/baboon.ascii.pgm 2 out0.pgm

#2. Bad Argument Count
echo "Echoing Bad Argument Count slice1a.pgm to nothing"
./pgmReduce images/slice1a.pgm 2

#3. Bad File Name
echo "Echoing Bad File Name slicea.pgm to out2.pgm" 
./pgmReduce images/slicea.pgm  2 out2.pgm

#4. Bad Magic Number
echo "Echoing Bad Magic Number slice3a.pgm to out3.pgm"
./pgmReduce images/slice3a.pgm 2 out3.pgm

#5. Bad Dimensions
echo "Echoing Bad Dimensions slice4a.pgm to out4.pgm"
./pgmReduce images/slice4a.pgm 2 out4.pgm

#6. Bad Max Gray Value
echo "Echoing Bad Max Gray Value slice5a.pgm to out5.pgm"
./pgmReduce images/slice5a.pgm 2 out5.pgm

#7. Bad Data
echo "Echoing Bad Data slice6a.pgm to out6.pgm"
./pgmReduce images/slice6a.pgm 2 out6.pgm

#8. Reduce binary file 
echo "Echoing Reduce binary file baboon.pgm to out8.pgm" 
./pgmReduce images/baboon.pgm 2 out8.pgm

#9. Bad n factor 
echo "Echoing Bad n factor baboon.pgm to out9.pgm" 
./pgmReduce images/baboon.pgm -1 out9.pgm

#Deleting pgmReduce temporary files
echo "Deleting pgmReduce temporary files"
rm out0.pgm out3.pgm out4.pgm out5.pgm out6.pgm out8.pgm



##############################################################
echo " "
#Test script for pgmTile
echo "Test script for pgmTile"
#1. No parameters 
echo "No parameters" 
./pgmTile

#2. Bad Argument Count
echo "Echoing Bad Argument Count slice1a.pgm to nothing"
./pgmTile images/slice1a.pgm 2

#3. Bad File Name
echo "Echoing Bad File Name slicea.pgm to out2.pgm" 
./pgmTile images/slicea.pgm  2 out2.pgm

#4. Bad Magic Number
echo "Echoing Bad Magic Number slice3a.pgm to out3.pgm"
./pgmTile images/slice3a.pgm 2 out3.pgm

#5. Bad Dimensions
echo "Echoing Bad Dimensions slice4a.pgm to out4.pgm"
./pgmTile images/slice4a.pgm 2 out4.pgm

#6. Bad Max Gray Value
echo "Echoing Bad Max Gray Value slice5a.pgm to out5.pgm"
./pgmTile images/slice5a.pgm 2 out5.pgm

#7. Bad Data
echo "Echoing Bad Data slice6a.pgm to out6.pgm"
./pgmTile images/slice6a.pgm 2 out6.pgm

#8. Reduce binary file 
echo "Echoing TILED binary file baboon.pgm to out8.pgm" 
./pgmTile images/baboon.pgm 2 out8.pgm

#9. Bad n factor 
echo "Echoing Bad n factor baboon.pgm to out9.pgm" 
./pgmTile images/baboon.pgm -1 out9.pgm

#Deleting pgmReduce temporary files
echo "Deleting pgmReduce temporary files"
rm out3.pgm out4.pgm out5.pgm out6.pgm out8.pgm



##############################################################
echo " "
#Test script for pgmAssemble
echo "Test script for pgmAssemble"
#1. No parameters 
echo "No parameters" 
./pgmAssemble

#2. Bad Argument Count
echo "Echoing Bad Argument Count slice1a.pgm to nothing"
./pgmAssemble images/slice1a.pgm 2

#3. Bad File Name
echo "Echoing Bad File Name slicea.pgm to out2.pgm" 
./pgmAssemble images/slicea.pgm  2 out2.pgm

#4. Bad Magic Number
echo "Echoing Bad Magic Number slice3a.pgm to out3.pgm"
./pgmAssemble images/slice3a.pgm 2 out3.pgm

#5. Bad Dimensions
echo "Echoing Bad Dimensions slice4a.pgm to out4.pgm"
./pgmAssemble images/slice4a.pgm 2 out4.pgm

#6. Bad Max Gray Value
echo "Echoing Bad Max Gray Value slice5a.pgm to out5.pgm"
./pgmAssemble images/slice5a.pgm 2 out5.pgm

#7. Bad Data
echo "Echoing Bad Data slice6a.pgm to out6.pgm"
./pgmAssemble images/slice6a.pgm 2 out6.pgm

#9. Bad n factor 
echo "Echoing Bad n factor baboon.pgm to out9.pgm" 
./pgmAssemble images/baboon.pgm -1 out9.pgm

#Deleting pgmReduce temporary files
echo "Deleting pgmReduce temporary files"
rm out3.pgm out4.pgm out5.pgm out6.pgm out9.pgm
echo " "

