   #include "Database.h"
   
    Data::Data(std::string filename){
        file.open(filename);
        if (!file)
        {
            std::cerr << "Connection error" << std::endl;
            throw std::runtime_error("No connection");
        }

        goodAnswers = 0;
        badAnswers = 0;
        
    }

    ComplexExp Data::loadFromFile(){
        
        ComplexExp Com;
        file >> Com;

        return Com;
    }

    void Data::testAllData(){
        while (!file.eof())
        {
            ComplexExp Complex;
            ComplexNum ComplexResult, ComplexAnswer;
            
            
            try
            {
                Complex = loadFromFile();
                ComplexResult = Complex.calculateResult();
            }
            catch(const std::exception& e)
            {   
                std::cerr << e.what() << '\n';
                continue;
            }
            
            std::cout << Complex << std::endl;

            bool loop=false;
            int i = 0;

           while(!loop && i < 3)
           {
        
               loop=true;
               try
            {   
                if (i>0)
                {
                    std::cout << "Check if data is entered like below" << std::endl;
                    std::cout << "(a+bi)" << std::endl;
                }
                
                std::cout << "Give Answer" << std::endl;
                std::cin >> ComplexAnswer;
            }
            catch(const std::exception& e)
            {   
                loop=false;
                i++;
                std::cerr << e.what() << '\n';
            }
           }
           
            
            
            if (ComplexResult==ComplexAnswer)
            {
                std::cout << "Good answer" << std::endl;
                goodAnswers++;
            }else{
                std::cout << "Bad answer, good answer is: " << ComplexResult << std::endl;
                badAnswers++;
            }
            
            std::cout << "Good answers: " << goodAnswers << std::endl;
            std::cout << "Bad answers: " << badAnswers << std::endl;
            
        }
        
    }