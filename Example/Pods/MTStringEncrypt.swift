//
//  MTStringEncrypt.swift
//  Pods
//
//  Created by pulei yu on 2023/5/21.
//

import Foundation
extension String {
    public func mtAES256Encryt() -> String? {
        guard let data = self.data(using: .utf8) as NSData? else { return nil }

        let cStr = cString(using: .utf8)
        let resultData = NSData(bytes: cStr, length: data.length)
        let encrypteStr = (resultData as Data).mtAES256Encrypt()
        return encrypteStr
    }

    public func mtAES256Decrypt() -> String? {
        if count < 20 { return nil }

        let key = (self as NSString).substring(to: 20)
        let content = (self as NSString).substring(from: 20)
        guard let data = Data(base64Encoded: content, options: .init(rawValue: 0)) else { return nil }

        let result = data.mtAES256Decrypt(key)
        return result
    }
}
