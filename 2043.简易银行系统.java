/*
 * @lc app=leetcode.cn id=2043 lang=java
 *
 * [2043] 简易银行系统
 */

// @lc code=start
class Bank {
    private long[] mBalance;

    public Bank(long[] balance) {
        mBalance = balance;
    }

    public boolean transfer(int account1, int account2, long money) {
        account1--;
        account2--;
        if (isNotExist(account1) || isNotExist(account2)) {
            return false;
        }
        if (mBalance[account1] >= money) {
            mBalance[account1] -= money;
            mBalance[account2] += money;
            return true;
        }
        return false;
    }

    public boolean deposit(int account, long money) {
        account--;
        if (isNotExist(account)) {
            return false;
        }
        mBalance[account] += money;
        return true;

    }

    public boolean withdraw(int account, long money) {
        account--;
        if (isNotExist(account)) {
            return false;
        }

        if (mBalance[account] >= money) {
            mBalance[account] -= money;
            return true;
        }
        return false;
    }

    private boolean isNotExist(int account) {
        return account >= mBalance.length || account < 0;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */
// @lc code=end
