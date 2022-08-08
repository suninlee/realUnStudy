#include <iostream>
#include <vector>

// 첫번째 문자열 5
   // std::string을 적극 이용해라
   // 인터넷 검색을 해서 함수들을 확인해라.

// 두번째 파일입출력 5
    // 확장자는 아무의미 없다.
    // 바이너리냐 텍스트냐가 중요한것.
    // 자주 저장해봤어야 합니다.
    // 테스트가 편해집니다.

// 세번째 디버깅 90
    // 디버깅을 잘한다는것은 사실 그냥 프로그래밍을 잘한다는 겁니다.
    // 프로그래머라는 겁니다.
    // 안된다라고 말하는것보다 설명하려고 노력하세요.
    // 단계적으로 설명하려고 노력하는게 가장 중요합니다.
    // 질문에 세부사항을 한꺼번에 보내면 됩니다.

    // 왜 그렇게 될거라고 생각했는지 근본지식을 상대에게 설명해줘야 합니다.
    // => 왜 안되는지를 안다.


std::string StringChange(const std::string& _Src, const std::string& _Old, const std::string& _New)
{
    std::string src = _Src;
    size_t tTarget = src.find(_Old);
    size_t tNext = _New.length();
    src.replace(tTarget, tNext, _New);

    return src;
}

// size_t capacity
// size_t size
// datatype* Arr;
std::vector<std::string> StringSplit(const std::string& _Src, const std::string& _Value)
{
    std::vector<std::string> vecResult;

    std::string str = "";
    std::string target = _Src;

    for (size_t i = 0; i < target.size(); i++)
    {
        if (target[i] == _Value[0])
        {
            vecResult.push_back(str);
            str = "";
        }
        else
        {
            str += target[i];
        }
    }

    if (str.length() != 0)
    {
        vecResult.push_back(str);
        str = "";
    }


    return vecResult;
}

int main()
{
    {
        //                  01234567
        std::string Test = "vvbasdf,,,gaaaaaaaa";

        size_t Pivotf = Test.find(",,,");
        size_t Pivotr = Test.rfind(",,,");

        {
            std::string Result = Test;

            //                                0번부터 7번째 글짜까지를 
            Result.replace(0, 7, ",,,");

            int cccc = 0;
        }

        {
            // std::string Result = Test;

            //                                7번부터 3번째 글짜까지를 
            // std::string Result = Test.substr(7, 3);
            //  0123456789
            // "vvbasdf,,,gaaaaaaaa";
            std::string Result = Test.substr(7, 3);
            int cccc = 0;
        }



        size_t PivotFail = Test.find("415645612");

        if (std::string::npos == Test.find("415645612"))
        {
            int a = 0;
        }



        // __int64

        int a = 0;

    }

    std::string Name = StringChange("AAABBBCCC", "BBB", "DDD");

    std::vector<std::string> Test = StringSplit("aaa,bbb,ccc", ",");

    // Test[0] == "aaa"
    // Test[1] == "bbb"
    // Test[2] == "ccc"

}