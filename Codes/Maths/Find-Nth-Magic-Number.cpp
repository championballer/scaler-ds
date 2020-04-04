    int Solution::solve(int A) {
        
        vector<int> powers;
        vector<int> magic_numbers;
        int current = 5;
        while(magic_numbers.size()<A)
        {
            //cout<<current<<endl;
            powers.push_back(current);
            vector<int> passive;
            magic_numbers.push_back(current);
            for(int i=0;i<magic_numbers.size()-1;i++)
            {
                int sum = current+magic_numbers[i];
                //cout<<sum<<" ";
                passive.push_back(sum);
            }
            //cout<<endl;
            for(int i=0;i<passive.size();i++)
            {
                magic_numbers.push_back(passive[i]);
            }
            current*=5;
        }
        
        return magic_numbers[A-1];
}
