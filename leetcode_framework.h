#ifndef LEETCODE_FRAMEWORK_H
#define LEETCODE_FRAMEWORK_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <sstream>
#include <iomanip>

using namespace std;

// 测试框架类
class TestFramework {
private:
    int total_tests = 0;
    int passed_tests = 0;
    
public:
    template<typename T>
    void assert_equal(const T& expected, const T& actual, const string& test_name) {
        total_tests++;
        if (expected == actual) {
            passed_tests++;
            cout << "✓ 测试通过: " << test_name << endl;
        } else {
            cout << "✗ 测试失败: " << test_name << endl;
            cout << "  期望: " << to_string_custom(expected) << endl;
            cout << "  实际: " << to_string_custom(actual) << endl;
        }
    }
    
    // 特化：vector 比较
    template<typename T>
    void assert_equal(const vector<T>& expected, const vector<T>& actual, const string& test_name) {
        total_tests++;
        if (expected == actual) {
            passed_tests++;
            cout << "✓ 测试通过: " << test_name << endl;
        } else {
            cout << "✗ 测试失败: " << test_name << endl;
            cout << "  期望: " << vector_to_string(expected) << endl;
            cout << "  实际: " << vector_to_string(actual) << endl;
        }
    }
    
    // 特化：vector<vector<T>> 比较
    template<typename T>
    void assert_equal(const vector<vector<T>>& expected, const vector<vector<T>>& actual, const string& test_name) {
        total_tests++;
        if (expected == actual) {
            passed_tests++;
            cout << "✓ 测试通过: " << test_name << endl;
        } else {
            cout << "✗ 测试失败: " << test_name << endl;
            cout << "  期望: " << vector2d_to_string(expected) << endl;
            cout << "  实际: " << vector2d_to_string(actual) << endl;
        }
    }
    
    void print_summary() {
        cout << "\n" << string(50, '=') << endl;
        cout << "测试结果汇总: " << passed_tests << "/" << total_tests << " 通过" << endl;
        if (passed_tests == total_tests) {
            cout << "🎉 恭喜！所有测试都通过了！" << endl;
        } else {
            cout << "⚠️  还有 " << (total_tests - passed_tests) << " 个测试未通过" << endl;
        }
        cout << string(50, '=') << endl;
    }
    
private:
    template<typename T>
    string to_string_custom(const T& val) {
        if constexpr (is_same_v<T, string>) {
            return "\"" + val + "\"";
        } else if constexpr (is_same_v<T, bool>) {
            return val ? "true" : "false";
        } else {
            return to_string(val);
        }
    }
    
    template<typename T>
    string vector_to_string(const vector<T>& vec) {
        if (vec.empty()) return "[]";
        stringstream ss;
        ss << "[";
        for (size_t i = 0; i < vec.size(); i++) {
            if (i > 0) ss << ", ";
            if constexpr (is_same_v<T, string>) {
                ss << "\"" << vec[i] << "\"";
            } else {
                ss << vec[i];
            }
        }
        ss << "]";
        return ss.str();
    }
    
    template<typename T>
    string vector2d_to_string(const vector<vector<T>>& vec) {
        if (vec.empty()) return "[]";
        stringstream ss;
        ss << "[";
        for (size_t i = 0; i < vec.size(); i++) {
            if (i > 0) ss << ", ";
            ss << vector_to_string(vec[i]);
        }
        ss << "]";
        return ss.str();
    }
};

// 全局测试对象
inline TestFramework test_framework;

// 辅助宏
#define RUN_TEST(func_call, expected, test_name) \
    test_framework.assert_equal(expected, func_call, test_name)

#define TEST_SUMMARY() \
    test_framework.print_summary()

#endif // LEETCODE_FRAMEWORK_H

