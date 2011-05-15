   while( i != len1 && i != len2 ){
      sum   = carry + (num1[i] - '0') + (num2[i] - '0');
      carry = sum/10;
      output[i++] = sum%10;
   }
   if(i == len1){
       while(i != len2){
          if( carry > 0 ){
            sum = carry + (num2[i] - '0');
            carry = sum/10;
            output[i++] = sum%10;
          }
          else output[i++] = num2[i];
       }
   }
   else{
       while(i != len1){
          if( carry > 0 ){
            sum = carry + (num1[i] - '0');
            carry = sum/10;
            output[i++] = sum%10;
          }
          else output[i++] = num1[i];
       }        
   }
